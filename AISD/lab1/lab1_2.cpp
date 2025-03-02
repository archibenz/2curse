#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

#ifdef _OPENMP
#include <omp.h>
#endif

using namespace std;
using namespace chrono;

// Функция сортировки выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    srand(time(0));
    vector<pair<int, double>> results;
    const int iterations = 10000;
    
    // Create file for storing sorted data
    ofstream outFile("selection_sorted_data.txt");

    for (int size = 100; size <= 2000; size += 100) {
        double total_time = 0.0;
        vector<int> lastSorted; // Store the last sorted array

        for (int iter = 0; iter < iterations; iter++) {
            vector<int> arr(size);
            for (int& num : arr) num = rand() % 1025 - 512;
            vector<int> copyArr = arr;

            auto start = high_resolution_clock::now();
            selectionSort(copyArr);
            auto stop = high_resolution_clock::now();
            total_time += duration_cast<microseconds>(stop - start).count() / 1000000.0;
            
            // Save the last sorted array for output
            if (iter == iterations - 1) {
                lastSorted = copyArr;
            }
        }

        // Write sorted data for this size to file
        outFile << "# Selection sort results for size = " << size << endl;
        for (const auto& num : lastSorted) {
            outFile << num << " ";
        }
        outFile << endl << endl;

        double avg_time = total_time / iterations;
        results.push_back({size, avg_time});
        
        cout << "Selection Sort (" << size << " элементов): " << avg_time << " сек" << endl;
    }

    sort(results.begin(), results.end());

    ofstream timeFile("selection_execution_time.txt");
    for (const auto& res : results) {
        timeFile << res.first << " " << res.second << endl;
    }
    timeFile.close();
    outFile.close();

    return 0;
}