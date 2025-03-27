#pragma once

// Вспомогательная функция для вычисления НОД:
template<typename T>
inline T gcd_template(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ==== Определения всех методов шаблонного класса Rational<T> ====

template<typename T>
Rational<T>::Rational() : numerator(0), denominator(1) {}

template<typename T>
Rational<T>::Rational(T n, T d) : numerator(n), denominator(d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

template<typename T>
void Rational<T>::reduce() {
    T divisor = gcd_template(std::abs(numerator), std::abs(denominator));
    numerator   /= divisor;
    denominator /= divisor;

    // Если знаменатель < 0, «переносим» знак к числителю
    if (denominator < 0) {
        numerator   = -numerator;
        denominator = -denominator;
    }
}

template<typename T>
void Rational<T>::print() const {
    std::cout << numerator << "/" << denominator << "\n";
}

// + 
template<typename T>
Rational<T> Rational<T>::operator+(const Rational& other) const {
    T newNum = numerator   * other.denominator + other.numerator   * denominator;
    T newDen = denominator * other.denominator;
    return Rational<T>(newNum, newDen);
}

// - 
template<typename T>
Rational<T> Rational<T>::operator-(const Rational& other) const {
    T newNum = numerator   * other.denominator - other.numerator   * denominator;
    T newDen = denominator * other.denominator;
    return Rational<T>(newNum, newDen);
}

// *
template<typename T>
Rational<T> Rational<T>::operator*(const Rational& other) const {
    T newNum = numerator   * other.numerator;
    T newDen = denominator * other.denominator;
    return Rational<T>(newNum, newDen);
}

// /
template<typename T>
Rational<T> Rational<T>::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    T newNum = numerator   * other.denominator;
    T newDen = denominator * other.numerator;
    return Rational<T>(newNum, newDen);
}

// ==
template<typename T>
bool Rational<T>::operator==(const Rational& other) const {
    return (numerator == other.numerator && denominator == other.denominator);
}

// !=
template<typename T>
bool Rational<T>::operator!=(const Rational& other) const {
    return !(*this == other);
}

// <
template<typename T>
bool Rational<T>::operator<(const Rational& other) const {
    return (numerator * other.denominator < other.numerator * denominator);
}

// >
template<typename T>
bool Rational<T>::operator>(const Rational& other) const {
    return (numerator * other.denominator > other.numerator * denominator);
}

// <=
template<typename T>
bool Rational<T>::operator<=(const Rational& other) const {
    return !(*this > other);
}

// >=
template<typename T>
bool Rational<T>::operator>=(const Rational& other) const {
    return !(*this < other);
}