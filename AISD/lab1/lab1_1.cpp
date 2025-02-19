#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Функция быстрой сортировки (Хоара)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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
    quickSort(copyArr, 0, copyArr.size() - 1);
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
    
    // Записываем отсортированный массив в файл
    ofstream outFile("quick_sorted_data.txt");
    if (!outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }
    for (int num : copyArr) {
        outFile << num << "\n";
    }
    outFile.close();
    
    // Записываем время выполнения сортировки в отдельный файл
    ofstream timeFile("quick_execution_time.txt");
    if (!timeFile) {
        cerr << "Ошибка открытия файла для записи времени!" << endl;
        return 1;
    }
    timeFile << duration << endl;
    timeFile.close();
    
    cout << "Отсортированные данные записаны в quick_sorted_data.txt" << endl;
    cout << "Время выполнения сортировки: " << duration << " секунд" << endl;
    
    return 0;
}