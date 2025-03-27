#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <cstddef>      // size_t
#include <stdexcept>    // для исключений std::out_of_range, std::underflow_error

/**
 * @brief Узел однонаправленного списка
 * @tparam U Тип данных, хранящихся в узле
 */
template<typename U>
class Node {
public:
    U data;
    Node* next;

    Node(const U& value, Node* nextNode = nullptr)
        : data(value), next(nextNode)
    {}
};

/**
 * @brief Шаблонный класс однонаправленного списка
 * @tparam T Тип элементов списка
 */
template<typename T>
class SinglyLinkedList {
private:
    Node<T>* head;  ///< Указатель на первый узел
    Node<T>* tail;  ///< Указатель на последний узел
    size_t size;    ///< Текущее число элементов

public:
    // Конструктор и деструктор
    SinglyLinkedList();
    ~SinglyLinkedList();

    // Методы добавления
    void append(const T& value);
    void prepend(const T& value);

    // Вставка и удаление по индексу
    void insertAt(size_t index, const T& value);
    T removeAt(size_t index);

    // Доступ к элементу
    T getAt(size_t index) const;

    // Служебные методы
    bool isEmpty() const { return size == 0; }
    size_t getSize() const { return size; }
};

// ===== Подключаем реализацию (inl) =====
#include "singlylinkedlist.inl"

#endif // SINGLYLINKEDLIST_H