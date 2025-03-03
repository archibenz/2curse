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
    outFile << "Size,Time(ns)\n";
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Test for various array sizes
    for (int size = 1000; size <= 1000000; size *= 2) {
        // Create a sorted array of size 'size'
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
        
        std::uniform_int_distribution<> distrib(0, size * 2); // Some targets will be in the array, some won't
        
        // Perform multiple searches to get accurate timing
        const int NUM_SEARCHES = 10000;
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < NUM_SEARCHES; i++) {
            int target = distrib(gen);
            bool found = binarySearch(arr, target);
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / NUM_SEARCHES;
        
        std::cout << "Binary Search - Array size: " << size << ", Average time: " << duration << " ns" << std::endl;
        outFile << size << "," << duration << "\n";
    }
    
    outFile.close();
    return 0;
}
