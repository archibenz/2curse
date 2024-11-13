#include <iostream>
#include <cmath>

double factorial(int n) {
    if (n == 0) return 1;
    double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    double x1, x2;

    // Ввод значений x1 и x2 с клавиатуры
    std::cout << "Введите значение x1: ";
    std::cin >> x1;
    std::cout << "Введите значение x2: ";
    std::cin >> x2;

    // Рассчеты для k, t и lambda
    int k = 20 + static_cast<int>(x1) + static_cast<int>(x2);  // k = 20 + x1 + x2
    double t = x1 / 100;  // t = x1 / 100
    double lambda = x2;   // lambda = x2

    // Расчет вероятности P(k, t) по формуле Пуассона
    double p_k_t = (std::pow(lambda * t, k) / factorial(k)) * std::exp(-lambda * t);

    // Вывод результата
    std::cout << "P(k = " << k << ", t = " << t << ") = " << p_k_t << std::endl;

    return 0;
}
