#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

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
    vector<pair<int, double>> results;
    const int iterations = 10000;
    
    // Create file for storing sorted data
    ofstream outFile("quick_sorted_data.txt");
    
    for (int size = 100; size <= 2000; size += 100) {
        double total_time = 0.0;
        vector<int> lastSorted; // Store the last sorted array
        
        for (int iter = 0; iter < iterations; iter++) {
            vector<int> arr(size);
            for (int& num : arr) num = rand() % 1025 - 512;
            vector<int> copyArr = arr;
            
            auto start = high_resolution_clock::now();
            quickSort(copyArr, 0, copyArr.size() - 1);
            auto stop = high_resolution_clock::now();
            total_time += duration_cast<microseconds>(stop - start).count() / 1000000.0;
            
            // Save the last sorted array for output
            if (iter == iterations - 1) {
                lastSorted = copyArr;
            }
        }
        
        // Write sorted data for this size to file
        outFile << "# Quick sort results for size = " << size << endl;
        for (const auto& num : lastSorted) {
            outFile << num << " ";
        }
        outFile << endl << endl;
        
        double avg_time = total_time / iterations;
        results.push_back({size, avg_time});
        
        cout << "Quick Sort (" << size << " элементов): " << avg_time << " сек" << endl;
    }
    
    sort(results.begin(), results.end());
    
    ofstream timeFile("quick_execution_time.txt");
    for (const auto& res : results) {
        timeFile << res.first << " " << res.second << endl;
    }
    timeFile.close();
    outFile.close();
    
    return 0;
}