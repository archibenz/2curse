#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Функция сортировки выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Ищем минимальный элемент в неотсортированной части массива
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Меняем местами текущий элемент и найденный минимальный
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    srand(time(0));
    const int SIZE = 1000; // Количество элементов
    vector<int> arr(SIZE);
    
    // Заполняем массив случайными числами в диапазоне [-512, 512]
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 1025 - 512;
    }
    
    // Делаем копию для тестирования
    vector<int> copyArr = arr;
    
    // Измеряем время выполнения сортировки
    high_resolution_clock::time_point start = high_resolution_clock::now();
    selectionSort(copyArr);
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    
    // Переводим время в секунды
    double duration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
    
    // Записываем отсортированный массив в файл
    ofstream outFile("selection_sorted_data.txt");
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи отсортированных данных!" << endl;
        return 1;
    }
    for (size_t i = 0; i < copyArr.size(); i++) {
        outFile << copyArr[i] << "\n";
    }
    outFile.close();
    
    // Записываем время выполнения сортировки в отдельный файл
    ofstream timeFile("selection_execution_time.txt");
    if (!timeFile) {
        cerr << "Ошибка открытия файла для записи времени!" << endl;
        return 1;
    }
    timeFile << duration << endl;
    timeFile.close();
    
    cout << "Отсортированные данные записаны в selection_sorted_data.txt" << endl;
    cout << "Время выполнения сортировки (выбором): " << duration << " секунд" << endl;
    
    return 0;
}