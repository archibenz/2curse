#include <iostream>
#include "singlylinkedlist.h"
#include "rational.h"

int main() {
    try {
        // Пример: список целых чисел
        SinglyLinkedList<int> intList;
        intList.append(10);
        intList.append(20);
        intList.prepend(5);       // [5, 10, 20]
        intList.insertAt(1, 15);  // [5, 15, 10, 20]

        std::cout << "intList elements:\n";
        for (size_t i = 0; i < intList.getSize(); ++i) {
            std::cout << intList.getAt(i) << " ";
        }
        std::cout << "\n";

        int removedInt = intList.removeAt(1); // удаляем элемент с индексом 1 (15)
        std::cout << "Removed element: " << removedInt << "\n\n";

        // Пример: список Rational<int>
        SinglyLinkedList<Rational<int>> ratList;
        ratList.append(Rational<int>(1, 2));  // 1/2
        ratList.append(Rational<int>(3, 4));  // 3/4
        ratList.prepend(Rational<int>(5, 6)); // [5/6, 1/2, 3/4]

        // Вставим 7/8 на позицию 1 => [5/6, 7/8, 1/2, 3/4]
        ratList.insertAt(1, Rational<int>(7, 8));

        std::cout << "ratList elements:\n";
        for (size_t i = 0; i < ratList.getSize(); ++i) {
            ratList.getAt(i).print();
        }

        // Удалим элемент с индексом 2 (где сейчас 1/2)
        Rational<int> removedRat = ratList.removeAt(2);
        std::cout << "Removed (Rational<int>): ";
        removedRat.print();
        std::cout << "\n";

        // Выведем элементы после удаления
        std::cout << "ratList after removal:\n";
        for (size_t i = 0; i < ratList.getSize(); ++i) {
            ratList.getAt(i).print();
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}