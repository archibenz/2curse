#include <iostream>
using namespace std;

class Array {
private:
    int* arr;  // указатель на массив
    int size;  // текущий размер массива
    int count; // счетчик элементов

    // Метод для расширения массива
    void resizeArray() {
        int newSize = size * 2;  // Увеличиваем размер массива в 2 раза
        int* newArr = new int[newSize];  // Создаем новый массив большего размера

        // Копируем элементы из старого массива в новый
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[i];
        }

        // Удаляем старый массив и заменяем его новым
        delete[] arr;
        arr = newArr;
        size = newSize;  // Обновляем размер
    }

public:
    // Конструктор с заданным начальным размером массива
    Array(int s) {
        size = s;
        arr = new int[size];
        count = 0;  // изначально массив пуст
    }

    // Деструктор
    ~Array() {
        delete[] arr;
    }

    // Копирующий конструктор
    Array(const Array& other) {
        size = other.size;
        count = other.count;
        arr = new int[size];
        for (int i = 0; i < count; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Ввод элементов массива
    void inputElements() {
        for (int i = 0; i < size; i++) {
            cout << "Введите элемент " << i + 1 << ": ";
            cin >> arr[i];
            count++;
        }
    }

    // Вывод элементов массива на экран
    void printElements() const {
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Добавление элемента в конец массива
    void addElement(int element) {
        // Если массив переполнен, увеличиваем его размер
        if (count == size) {
            resizeArray();
        }
        arr[count] = element;
        count++;
    }

    // Объединение двух массивов
    Array merge(const Array& other) {
        Array result(size + other.size);  // создаем новый массив большего размера

        for (int i = 0; i < count; i++) {
            result.addElement(arr[i]);
        }
        for (int i = 0; i < other.count; i++) {
            result.addElement(other.arr[i]);
        }

        return result;
    }

    // Вычисление суммы элементов массива
    int sumElements() const {
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {
    // Пример использования класса

    // Создаем массив на 5 элементов
    Array arr1(5);

    // Вводим элементы массива
    arr1.inputElements();

    // Выводим элементы массива
    cout << "Элементы первого массива: ";
    arr1.printElements();

    // Добавляем элемент в конец массива
    arr1.addElement(10);
    cout << "После добавления элемента: ";
    arr1.printElements();

    // Создаем второй массив на 3 элемента
    Array arr2(3);
    arr2.inputElements();

    // Объединяем два массива
    Array mergedArray = arr1.merge(arr2);
    cout << "Объединённый массив: ";
    mergedArray.printElements();

    // Вычисляем сумму элементов объединённого массива
    cout << "Сумма элементов объединённого массива: " << mergedArray.sumElements() << endl;

    return 0;
}