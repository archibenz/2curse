

#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

// Методы одномерной оптимизации

// Метод дихотомии
double dichotomy(const std::function<double(double)>& f, double a, double b, double eps) {
    double l = a, r = b;
    double delta = eps / 2;
    while (r - l > eps) {
        double x1 = (l + r - delta) / 2;
        double x2 = (l + r + delta) / 2;
        if (f(x1) < f(x2))
            r = x2;
        else
            l = x1;
    }
    return (l + r) / 2;
}

// Метод золотого сечения
double goldenRatio(const std::function<double(double)>& f, double a, double b, double eps) {
    const double phi = (1 + std::sqrt(5.0)) / 2;
    double l = a, r = b;
    double x1 = r - (r - l) / phi;
    double x2 = l + (r - l) / phi;
    double f1 = f(x1);
    double f2 = f(x2);
    while (r - l > eps) {
        if (f1 < f2) {
            r = x2;
            x2 = x1;
            f2 = f1;
            x1 = r - (r - l) / phi;
            f1 = f(x1);
        } else {
            l = x1;
            x1 = x2;
            f1 = f2;
            x2 = l + (r - l) / phi;
            f2 = f(x2);
        }
    }
    return (l + r) / 2;
}

// Метод Фибоначчи
double fibonacci(const std::function<double(double)>& f, double a, double b, double eps) {
    std::vector<long long> F = {1, 1};
    while (F.back() < (b - a) / eps) {
        F.push_back(F[F.size() - 1] + F[F.size() - 2]);
    }
    int N = F.size() - 1;
    double l = a, r = b;
    int k = 1;
    double x1 = l + double(F[N - 2]) / F[N] * (r - l);
    double x2 = l + double(F[N - 1]) / F[N] * (r - l);
    double f1 = f(x1);
    double f2 = f(x2);
    while (k < N - 1) {
        if (f1 > f2) {
            l = x1;
            x1 = x2;
            f1 = f2;
            x2 = l + double(F[N - k - 1]) / F[N - k] * (r - l);
            f2 = f(x2);
        } else {
            r = x2;
            x2 = x1;
            f2 = f1;
            x1 = l + double(F[N - k - 2]) / F[N - k] * (r - l);
            f1 = f(x1);
        }
        k++;
    }
    return (l + r) / 2;
}

// Метод квадратичной аппроксимации (Пауэлла)
double parabolicInterpolation(const std::function<double(double)>& f, double x1, double x2, double x3, double eps) {
    double f1 = f(x1), f2 = f(x2), f3 = f(x3), x;
    while (std::abs(x3 - x1) > eps) {
        double numerator = (f1*(x2*x2 - x3*x3) + f2*(x3*x3 - x1*x1) + f3*(x1*x1 - x2*x2));
        double denominator = 2*(f1*(x2 - x3) + f2*(x3 - x1) + f3*(x1 - x2));
        if (denominator == 0) break;
        x = numerator / denominator;
        double fx = f(x);
        if (x > x2) {
            if (fx < f2) {
                x1 = x2; f1 = f2;
                x2 = x;  f2 = fx;
            } else {
                x3 = x;  f3 = fx;
            }
        } else {
            if (fx < f2) {
                x3 = x2; f3 = f2;
                x2 = x;  f2 = fx;
            } else {
                x1 = x;  f1 = fx;
            }
        }
    }
    return x2;
}

int main() {
    // Задайте здесь вашу функцию
    auto f = [](double x) {
        return x * x + 4 * std::sin(x);
    };

    double a, b, eps;
    std::cout << "Введите начальный интервал [a b]: ";
    if (!(std::cin >> a >> b)) return 0;
    std::cout << "Введите требуемую точность: ";
    if (!(std::cin >> eps)) return 0;

    double x_dicho = dichotomy(f, a, b, eps);
    std::cout << "Метод дихотомии: x* = " << x_dicho << ", f(x*) = " << f(x_dicho) << std::endl;

    double x_golden = goldenRatio(f, a, b, eps);
    std::cout << "Метод золотого сечения: x* = " << x_golden << ", f(x*) = " << f(x_golden) << std::endl;

    double x_fib = fibonacci(f, a, b, eps);
    std::cout << "Метод Фибоначчи: x* = " << x_fib << ", f(x*) = " << f(x_fib) << std::endl;

    double x1 = a;
    double x2 = a + (b - a) / 3;
    double x3 = a + 2 * (b - a) / 3;
    double x_par = parabolicInterpolation(f, x1, x2, x3, eps);
    std::cout << "Метод квадратичной аппроксимации (Пауэлла): x* = " << x_par << ", f(x*) = " << f(x_par) << std::endl;

    return 0;
}