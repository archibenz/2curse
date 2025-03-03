#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>
#include <unordered_set>
#include <iomanip>

int main() {
    std::ofstream outFile("hash_search_results.txt");
    outFile << "Size,Time(ns)\n";
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Test for various array sizes
    for (int size = 1000; size <= 1000000; size *= 2) {
        // Create a hash table of size 'size'
        std::unordered_set<int> hashTable;
        for (int i = 0; i < size; i++) {
            hashTable.insert(i);
        }
        
        std::uniform_int_distribution<> distrib(0, size * 2); // Some targets will be in the hash table, some won't
        
        // Perform multiple searches to get accurate timing
        const int NUM_SEARCHES = 10000;
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < NUM_SEARCHES; i++) {
            int target = distrib(gen);
            bool found = (hashTable.find(target) != hashTable.end());
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / NUM_SEARCHES;
        
        std::cout << "Hash Search - Table size: " << size << ", Average time: " << duration << " ns" << std::endl;
        outFile << size << "," << duration << "\n";
    }
    
    outFile.close();
    
    // Generate a report file
    std::ofstream report("search_algorithms_report.txt");
    report << "Отчет по лабораторной работе №2: Методы поиска\n\n";
    
    report << "1. Описание алгоритмов\n";
    report << "---------------------\n";
    report << "а) Бинарный поиск:\n";
    report << "   - Работает только с отсортированным массивом\n";
    report << "   - Сравнивает искомый элемент со средним элементом массива\n";
    report << "   - Если средний элемент равен искомому, поиск завершен\n";
    report << "   - Если средний элемент больше искомого, поиск продолжается в левой половине массива\n";
    report << "   - Если средний элемент меньше искомого, поиск продолжается в правой половине массива\n";
    report << "   - Временная сложность: O(log n)\n\n";
    
    report << "б) Поиск по сбалансированному дереву (BST):\n";
    report << "   - Использует структуру данных 'дерево' для организации элементов\n";
    report << "   - В сбалансированном дереве (например, AVL или Red-Black) высота поддеревьев отличается не более чем на 1\n";
    report << "   - Поиск выполняется путем сравнения с корнем и переходом в левое или правое поддерево\n";
    report << "   - Временная сложность: O(log n)\n\n";
    
    report << "в) Поиск хешированием:\n";
    report << "   - Использует хеш-функцию для быстрого доступа к данным\n";
    report << "   - Хеш-функция преобразует ключ в индекс массива\n";
    report << "   - В идеальном случае позволяет найти элемент за O(1)\n";
    report << "   - При коллизиях (одинаковый хеш для разных ключей) временная сложность может возрасти\n";
    report << "   - Средняя временная сложность: O(1)\n\n";
    
    report << "3. Результаты измерений будут представлены в графике\n\n";
    
    report << "5. Выводы\n";
    report << "---------\n";
    report << "- Бинарный поиск демонстрирует хорошую производительность O(log n), но требует предварительной сортировки данных.\n";
    report << "- Поиск по сбалансированному дереву также имеет сложность O(log n), но с немного большей константой из-за дополнительных операций.\n";
    report << "- Поиск хешированием в среднем работает за O(1), что делает его наиболее эффективным для больших объемов данных.\n";
    report << "- Для небольших объемов данных разница между алгоритмами может быть незначительной.\n";
    report << "- Выбор алгоритма поиска зависит от конкретной задачи, структуры данных и требований к скорости/памяти.\n";
    
    report.close();
    
    std::cout << "All measurements completed. Run comparison-plot.py to generate visualization." << std::endl;
    
    return 0;
}
