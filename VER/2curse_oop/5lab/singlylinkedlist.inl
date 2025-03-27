#pragma once

// ==== Реализация методов шаблонного класса SinglyLinkedList<T> ====

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
    : head(nullptr), tail(nullptr), size(0)
{ }

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

template<typename T>
void SinglyLinkedList<T>::append(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

template<typename T>
void SinglyLinkedList<T>::prepend(const T& value) {
    Node<T>* newNode = new Node<T>(value, head);
    head = newNode;
    if (!tail) {
        tail = head;
    }
    ++size;
}

template<typename T>
void SinglyLinkedList<T>::insertAt(size_t index, const T& value) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    if (index == size) {
        append(value);
        return;
    }

    Node<T>* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    Node<T>* newNode = new Node<T>(value, current->next);
    current->next = newNode;
    ++size;
}

template<typename T>
T SinglyLinkedList<T>::removeAt(size_t index) {
    if (isEmpty()) {
        throw std::underflow_error("Cannot remove from an empty list");
    }
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;
    T value;

    if (index == 0) {
        value = current->data;
        head = head->next;
        delete current;
        if (!head) {
            tail = nullptr;
        }
    } else {
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node<T>* temp = current->next;
        value = temp->data;
        current->next = temp->next;
        if (!current->next) {
            tail = current;
        }
        delete temp;
    }
    --size;
    return value;
}

template<typename T>
T SinglyLinkedList<T>::getAt(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}