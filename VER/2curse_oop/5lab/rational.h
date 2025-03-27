#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>
#include <cmath> // std::abs

/**
 * @brief Шаблонный класс для рациональных чисел
 * @tparam T Целочисленный тип (int, long long и т.д.)
 */
template<typename T>
class Rational {
private:
    T numerator;   ///< Числитель
    T denominator; ///< Знаменатель

    void reduce(); ///< Приведение к редуцированной форме (деление на НОД)

public:
    // Конструкторы
    Rational();                  // 0/1 по умолчанию
    Rational(T n, T d);          // с параметрами

    // Вывод на экран
    void print() const;

    // Арифметические операции
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Операции сравнения
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other)  const;
    bool operator>(const Rational& other)  const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
};

// ===== Подключаем реализацию из файла .inl =====
#include "rational.inl"

#endif // RATIONAL_H