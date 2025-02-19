#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Функция сортировки вставками
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));
    const int SIZE = 1000; // Количество элементов
    vector<int> arr(SIZE);

    // Заполняем массив случайными числами в диапазоне [-512, 512]
    for (int& num : arr) {
        num = rand() % 1025 - 512;
    }

    vector<int> copyArr = arr; // Копируем массив для многократного тестирования

    // Измерение времени выполнения сортировки
    auto start = high_resolution_clock::now();
    
    insertionSort(copyArr);

    auto stop = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(stop - start).count() / 1000000.0;

    // Записываем отсортированный массив в файл
    ofstream outFile("sorted_data.txt");
    if (!outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }
    for (int num : copyArr) {
        outFile << num << "\n";
    }
    outFile.close();

    // Записываем время выполнения сортировки в отдельный файл
    ofstream timeFile("execution_time.txt");
    if (!timeFile) {
        cerr << "Ошибка открытия файла для записи времени!" << endl;
        return 1;
    }
    timeFile << duration << endl;
    timeFile.close();

    cout << "Отсортированные данные записаны в sorted_data.txt" << endl;
    cout << "Время выполнения сортировки: " << duration << " секунд" << endl;

    return 0;
}