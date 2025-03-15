#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cstdlib>

// -----------------------------------------------------------
// 1. Генерация случайных строк
// -----------------------------------------------------------

// Генерация случайной строки заданной длины из букв [a-z]
std::string generateRandomString(int length) {
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    static std::random_device rd;
    static std::mt19937_64 rng(rd());
    static std::uniform_int_distribution<int> dist(0, 25);

    std::string result;
    result.reserve(length);
    for (int i = 0; i < length; i++) {
        result.push_back(alphabet[dist(rng)]);
    }
    return result;
}

// Генерация случайной подстроки длиной от minLen до maxLen
std::string generateRandomSubstring(int minLen, int maxLen) {
    static std::random_device rd;
    static std::mt19937_64 rng(rd());
    std::uniform_int_distribution<int> dist(minLen, maxLen);
    int length = dist(rng);
    return generateRandomString(length);
}

// -----------------------------------------------------------
// 2. Алгоритмы поиска подстроки (возвращают все вхождения)
// -----------------------------------------------------------

// 2.1. Алгоритм Кнута–Морриса–Пратта (KMP)
std::vector<int> KMPsearch(const std::string &text, const std::string &pattern) {
    std::vector<int> result;
    if (pattern.empty()) return result;

    // Префикс-функция (lps — longest prefix-suffix)
    std::vector<int> lps(pattern.size(), 0);
    {
        int j = 0;  // длина текущего совпавшего префикса
        for (int i = 1; i < (int)pattern.size(); ) {
            if (pattern[i] == pattern[j]) {
                lps[i] = j + 1;
                i++;
                j++;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Поиск
    int i = 0; // индекс в text
    int j = 0; // индекс в pattern
    while (i < (int)text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == (int)pattern.size()) {
                result.push_back(i - j);
                j = lps[j - 1]; // продолжаем искать
            }
        } else {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

// 2.2. Алгоритм Бойера–Мура (упрощённая реализация)
std::vector<int> BoyerMooreSearch(const std::string &text, const std::string &pattern) {
    std::vector<int> result;
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return result;

    // Таблица смещений (bad character table)
    const int ALPHABET_SIZE = 256;
    std::vector<int> badChar(ALPHABET_SIZE, -1);
    for (int i = 0; i < m; i++) {
        badChar[(unsigned char)pattern[i]] = i;
    }

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }
        if (j < 0) {
            result.push_back(shift);
            shift += (shift + m < n) ? m - badChar[(unsigned char)text[shift + m]] : 1;
        } else {
            int badIndex = badChar[(unsigned char)text[shift + j]];
            int move = j - badIndex;
            if (move < 1) move = 1;
            shift += move;
        }
    }
    return result;
}

// 2.3. Алгоритм Рабина–Карпа
std::vector<int> RabinKarpSearch(const std::string &text, const std::string &pattern) {
    std::vector<int> result;
    int n = text.size();
    int m = pattern.size();
    if (m == 0 || n < m) return result;

    const unsigned long long base = 257ULL;
    const unsigned long long mod  = 1000000007ULL; // большое простое число

    unsigned long long power = 1;
    for (int i = 0; i < m - 1; i++) {
        power = (power * base) % mod;
    }

    unsigned long long patternHash = 0;
    unsigned long long windowHash  = 0;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + (unsigned char)pattern[i]) % mod;
        windowHash  = (windowHash  * base + (unsigned char)text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
        if (i < n - m) {
            unsigned char leftChar  = (unsigned char)text[i];
            unsigned char rightChar = (unsigned char)text[i + m];
            unsigned long long tmp = (windowHash + mod - (leftChar * power) % mod) % mod;
            tmp = (tmp * base + rightChar) % mod;
            windowHash = tmp;
        }
    }
    return result;
}

// -----------------------------------------------------------
// 3. Основная программа для тестирования
// -----------------------------------------------------------

int main() {
    std::ofstream outFile("substring_search_results.txt");
    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи результатов!\n";
        return 1;
    }
    outFile << "StringLength;TimeKMP(ms);TimeBoyerMoore(ms);TimeRabinKarp(ms)\n";

    // Генерация подстрок для каждого алгоритма (длина 3-5 символов)
    std::string patternKMP = generateRandomSubstring(3, 5);
    std::string patternBoyerMoore = generateRandomSubstring(3, 5);
    std::string patternRabinKarp = generateRandomSubstring(3, 5);

    // Перебор длины строки от 1000 до 3000 с шагом 100
    for (int length = 1000; length <= 3000; length += 100) {
        std::string text = generateRandomString(length);
        const int NUM_RUNS = 10000;

        // Измерение времени для KMP
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < NUM_RUNS; i++) {
            std::vector<int> foundPositions = KMPsearch(text, patternKMP);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff = end - start;
        double timeKMP = diff.count();

        // Измерение времени для Бойера–Мура
        auto start2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < NUM_RUNS; i++) {
            std::vector<int> foundPositions = BoyerMooreSearch(text, patternBoyerMoore);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff2 = end2 - start2;
        double timeBM = diff2.count();

        // Измерение времени для Рабина–Карпа
        auto start3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < NUM_RUNS; i++) {
            std::vector<int> foundPositions = RabinKarpSearch(text, patternRabinKarp);
        }
        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff3 = end3 - start3;
        double timeRK = diff3.count();

        outFile << length << ";"
                << timeKMP << ";"
                << timeBM  << ";"
                << timeRK  << "\n";

        std::cout << "Length = " << length
                  << " | KMP(ms) = " << timeKMP
                  << " | BoyerMoore(ms) = " << timeBM
                  << " | RabinKarp(ms) = " << timeRK << std::endl;
    }

    outFile.close();
    std::cout << "Результаты сохранены в файл substring_search_results.txt\n";
    return 0;
}