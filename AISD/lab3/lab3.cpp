#include <iostream>
#include <chrono>
#include <vector>
#include <string>

// 1. Iterative factorial calculation
/**
 * Calculates factorial using iteration (loops)
 * This approach avoids function call overhead by using a simple loop
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
unsigned long long factorial_iterative(int n) {
    // Base cases
    if (n < 0) {
        std::cout << "Факториал не определен для отрицательных чисел!" << std::endl;
        return 0;
    }
    if (n == 0 || n == 1) return 1; // 0! = 1, 1! = 1
    
    // Iterative calculation using a loop
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 2. Recursive factorial calculation
/**
 * Calculates factorial using recursion
 * This demonstrates the elegance of recursive solutions but has function call overhead
 * Time complexity: O(n)
 * Space complexity: O(n) - due to call stack
 */
unsigned long long factorial_recursive(int n) {
    // Base cases
    if (n < 0) {
        std::cout << "Факториал не определен для отрицательных чисел!" << std::endl;
        return 0;
    }
    if (n == 0 || n == 1) return 1; // Base case for recursion
    
    // Recursive case: n! = n * (n-1)!
    return n * factorial_recursive(n - 1);
}

// 3. Binary Tree implementation
/**
 * Node structure for a binary search tree
 * Each node contains an integer value and pointers to left and right children
 */
struct Node {
    int value;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * Inserts a value into the binary search tree
 * The binary search tree property ensures:
 * - Values less than the current node go to the left subtree
 * - Values greater than the current node go to the right subtree
 * - Equal values are not added (to avoid duplicates)
 */
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node
    if (root == nullptr) {
        return new Node(value);
    }
    
    // Otherwise, recursively insert down the tree
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    // If the value is already in the tree, we don't insert it again (BST property)
    
    return root;
}

/**
 * Pre-order traversal: Root - Left - Right
 * Visits the current node before its children
 * Useful for creating a copy of the tree or prefix expression evaluation
 */
void preOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    std::cout << root->value << " ";  // Visit root
    preOrderTraversal(root->left);    // Visit left subtree
    preOrderTraversal(root->right);   // Visit right subtree
}

/**
 * In-order traversal: Left - Root - Right
 * Visits the left subtree, then current node, then right subtree
 * For BST, this gives nodes in ascending order
 */
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    inOrderTraversal(root->left);     // Visit left subtree
    std::cout << root->value << " ";  // Visit root
    inOrderTraversal(root->right);    // Visit right subtree
}

/**
 * Post-order traversal: Left - Right - Root
 * Visits the current node after its children
 * Useful for deleting the tree or postfix expression evaluation
 */
void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    postOrderTraversal(root->left);   // Visit left subtree
    postOrderTraversal(root->right);  // Visit right subtree
    std::cout << root->value << " ";  // Visit root
}

/**
 * Frees memory by deleting all nodes in the tree
 */
void deleteTree(Node* root) {
    if (root == nullptr) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

/**
 * Compares performance of iterative and recursive factorial calculations
 */
void compareFactorialPerformance(int n) {
    // Timing for iterative approach
    auto start_iterative = std::chrono::high_resolution_clock::now();
    unsigned long long result_iterative = factorial_iterative(n);
    auto end_iterative = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> time_iterative = end_iterative - start_iterative;
    
    // Timing for recursive approach
    auto start_recursive = std::chrono::high_resolution_clock::now();
    unsigned long long result_recursive = factorial_recursive(n);
    auto end_recursive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> time_recursive = end_recursive - start_recursive;
    
    // Display results
    std::cout << "Сравнение производительности для вычисления факториала числа " << n << ":" << std::endl;
    std::cout << "Итеративный результат: " << result_iterative << ", Время: " 
              << time_iterative.count() << " микросекунд" << std::endl;
    std::cout << "Рекурсивный результат: " << result_recursive << ", Время: " 
              << time_recursive.count() << " микросекунд" << std::endl;
    
    // Compare the times
    if (time_iterative.count() < time_recursive.count()) {
        std::cout << "Итеративный подход быстрее в " 
                  << (time_recursive.count() / time_iterative.count()) 
                  << " раз." << std::endl;
    } else {
        std::cout << "Рекурсивный подход быстрее в " 
                  << (time_iterative.count() / time_recursive.count()) 
                  << " раз." << std::endl;
    }
    
    std::cout << "Примечание: Рекурсивный подход имеет накладные расходы на вызов функций, "
              << "что обычно делает его медленнее для больших значений N." << std::endl;
}

int main() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n========= ДЕМОНСТРАЦИЯ АЛГОРИТМОВ =========" << std::endl;
        std::cout << "1. Вычислить факториал (итеративно)" << std::endl;
        std::cout << "2. Вычислить факториал (рекурсивно)" << std::endl;
        std::cout << "3. Операции с бинарным деревом" << std::endl;
        std::cout << "4. Сравнить производительность вычисления факториала" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Введите ваш выбор (1-5): ";
        
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                int n;
                std::cout << "Введите неотрицательное целое число для вычисления факториала: ";
                std::cin >> n;
                
                std::cout << "Факториал числа " << n << " (итеративно): " 
                          << factorial_iterative(n) << std::endl;
                break;
            }
            
            case 2: {
                int n;
                std::cout << "Введите неотрицательное целое число для вычисления факториала: ";
                std::cin >> n;
                
                std::cout << "Факториал числа " << n << " (рекурсивно): " 
                          << factorial_recursive(n) << std::endl;
                break;
            }
            
            case 3: {
                Node* root = nullptr;
                int numValues;
                
                std::cout << "Введите количество значений для добавления в дерево: ";
                std::cin >> numValues;
                
                std::cout << "Введите " << numValues << " целых чисел:" << std::endl;
                for (int i = 0; i < numValues; i++) {
                    int value;
                    std::cin >> value;
                    root = insert(root, value);
                }
                
                std::cout << "\nОбходы дерева:" << std::endl;
                
                std::cout << "Прямой обход (Корень-Левый-Правый): ";
                preOrderTraversal(root);
                std::cout << std::endl;
                
                std::cout << "Центрированный обход (Левый-Корень-Правый): ";
                inOrderTraversal(root);
                std::cout << std::endl;
                
                std::cout << "Обратный обход (Левый-Правый-Корень): ";
                postOrderTraversal(root);
                std::cout << std::endl;
                
                // Clean up the tree
                deleteTree(root);
                break;
            }
            
            case 4: {
                int n;
                std::cout << "Введите неотрицательное целое число для сравнения производительности: ";
                std::cin >> n;
                
                compareFactorialPerformance(n);
                break;
            }
            
            case 5:
                std::cout << "Выход из программы. До свидания!" << std::endl;
                break;
                
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }
    
    return 0;
}
