#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>
#include <set>
#include <iomanip>

int main() {
    std::ofstream outFile("bst_search_results.txt");
    outFile << "Size,Time(ns)\n";
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Test for various array sizes
    for (int size = 1000; size <= 1000000; size *= 2) {
        // Create a balanced BST (using std::set) of size 'size'
        std::set<int> bst;
        for (int i = 0; i < size; i++) {
            bst.insert(i);
        }
        
        std::uniform_int_distribution<> distrib(0, size * 2); // Some targets will be in the BST, some won't
        
        // Perform multiple searches to get accurate timing
        const int NUM_SEARCHES = 10000;
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < NUM_SEARCHES; i++) {
            int target = distrib(gen);
            bool found = (bst.find(target) != bst.end());
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / NUM_SEARCHES;
        
        std::cout << "BST Search - Tree size: " << size << ", Average time: " << duration << " ns" << std::endl;
        outFile << size << "," << duration << "\n";
    }
    
    outFile.close();
    return 0;
}
