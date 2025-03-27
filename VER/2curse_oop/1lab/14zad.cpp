#include <iostream>
using namespace std;

// Вспомогательная функция для нахождения наибольшего общего делителя (НОД)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Rational {
private:
    int numerator;   // числитель
    int denominator; // знаменатель

    // Приведение дроби к редуцированной форме
    void reduce() {
        int divisor = gcd(abs(numerator), abs(denominator)); // находим НОД
        numerator /= divisor;
        denominator /= divisor;
        // Если знаменатель отрицательный, переносим знак в числитель
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Конструктор по умолчанию
    Rational() : numerator(0), denominator(1) {}

    // Конструктор с параметрами
    Rational(int n, int d) : numerator(n), denominator(d) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        reduce(); // Приводим к редуцированной форме сразу
    }

    // Вывод рационального числа
    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    // Операция сложения
    Rational operator+(const Rational& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator); // Вернем результат в виде нового объекта
    }

    // Операция вычитания
    Rational operator-(const Rational& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator); // Вернем результат в виде нового объекта
    }

    // Операция умножения
    Rational operator*(const Rational& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator); // Вернем результат в виде нового объекта
    }

    // Операция деления
    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Rational(newNumerator, newDenominator); // Вернем результат в виде нового объекта
    }

    // Операция равенства
    bool operator==(const Rational& other) const {
        return (numerator == other.numerator && denominator == other.denominator);
    }

    // Операция неравенства
    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    // Операция сравнения меньше
    bool operator<(const Rational& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Операция сравнения больше
    bool operator>(const Rational& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Операция сравнения меньше или равно
    bool operator<=(const Rational& other) const {
        return !(*this > other);
    }

    // Операция сравнения больше или равно
    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }
};

int main() {
    int num1, den1, num2, den2;

    // Ввод числителя и знаменателя для первого числа
    cout << "Введите числитель и знаменатель для первого числа (через пробел): ";
    cin >> num1 >> den1;

    // Ввод числителя и знаменателя для второго числа
    cout << "Введите числитель и знаменатель для второго числа (через пробел): ";
    cin >> num2 >> den2;

    try {
        // Создание двух рациональных чисел
        Rational r1(num1, den1);
        Rational r2(num2, den2);

        // Сложение
        Rational r3 = r1 + r2;
        cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = ";
        r3.print();

        // Вычитание
        Rational r4 = r1 - r2;
        cout << num1 << "/" << den1 << " - " << num2 << "/" << den2 << " = ";
        r4.print();

        // Умножение
        Rational r5 = r1 * r2;
        cout << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = ";
        r5.print();

        // Деление
        Rational r6 = r1 / r2;
        cout << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = ";
        r6.print();

    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}