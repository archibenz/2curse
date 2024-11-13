#include <iostream>
#include <cmath>

int main() {
    double x1, x2;

    // Ввод значений x1 и x2 с клавиатуры
    std::cout << "Введите значение x1: ";
    std::cin >> x1;
    std::cout << "Введите значение x2: ";
    std::cin >> x2;

    // Рассчет для mu1 = x1 и mu2 = x2
    double mu1 = x1;
    double mu2 = x2;

    std::cout << "\nРезультаты для mu1 = " << mu1 << " (c^-1):\n";
    std::cout << "t\t\th(t)\n";
    for (int t = 0; t <= 10; ++t) {
        double h = 1 - std::exp(-mu1 * t);
        std::cout << t << "\t\t" << h << std::endl;
    }

    std::cout << "\nРезультаты для mu2 = " << mu2 << " (c^-1):\n";
    std::cout << "t\t\th(t)\n";
    for (int t = 0; t <= 10; ++t) {
        double h = 1 - std::exp(-mu2 * t);
        std::cout << t << "\t\t" << h << std::endl;
    }

    return 0;
}
