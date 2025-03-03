#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>

// Binary Search implementation
bool binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return true;
        
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}

int main() {
    std::ofstream outFile("binary_search_results.txt");
    outFile << "Size,Time(s)\n";
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Test for various array sizes from 1000 to 50000 with step 1000
    for (int size = 1000; size <= 50000; size += 1000) {
        // Create a sorted array of size 'size'
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
        
        std::uniform_int_distribution<> distrib(0, size * 2); // Some targets will be in the array, some won't
        
        // Perform multiple searches to get accurate timing
        const int NUM_SEARCHES = 10000;
        
        // Measure total time for all searches in microseconds
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < NUM_SEARCHES; i++) {
            int target = distrib(gen);
            bool found = binarySearch(arr, target);
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        
        // Calculate total time in microseconds first
        long long totalMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        
        // Convert to seconds by dividing by 10^6 and then by number of searches
        double averageTimeSeconds = (double)totalMicroseconds / (1000000.0 * NUM_SEARCHES);
        
        std::cout << "Binary Search - Array size: " << size << ", Average time: " << averageTimeSeconds << " s" << std::endl;
        outFile << size << "," << averageTimeSeconds << "\n";
    }
    
    outFile.close();
    return 0;
}
