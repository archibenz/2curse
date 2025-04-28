#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <fstream>

// Метод дихотомии с логированием
std::vector<double> dichotomy_history(const std::function<double(double)>& f,
                                      double a, double b, double eps) {
    std::vector<double> hist;
    double l = a, r = b;
    double delta = eps/2;
    while (r - l > eps) {
        double x1 = (l+r-delta)/2;
        double x2 = (l+r+delta)/2;
        double xm = (l + r) / 2;
        hist.push_back(xm);
        if (f(x1) < f(x2))
            r = x2;
        else
            l = x1;
    }
    hist.push_back((l+r)/2);  // финальное
    return hist;
}

// Метод дихотомии без логирования
double dichotomy(const std::function<double(double)>& f,
                double a, double b, double eps) {
    double l = a, r = b;
    double delta = eps/2;
    while (r - l > eps) {
        double x1 = (l+r-delta)/2;
        double x2 = (l+r+delta)/2;
        if (f(x1) < f(x2))
            r = x2;
        else
            l = x1;
    }
    return (l+r)/2;  // финальное значение
}

// Метод золотого сечения
double goldenRatio(const std::function<double(double)>& f, double a, double b, double eps) {
    const double phi = (1 + std::sqrt(5.0)) / 2;
    double l = a, r = b;
    double x1 = r - (r - l) / phi;
    double x2 = l + (r - l) / phi;
    double f1 = f(x1), f2 = f(x2);
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

// Метод золотого сечения с логированием
std::vector<double> goldenRatio_history(const std::function<double(double)>& f, double a, double b, double eps) {
    std::vector<double> hist;
    const double phi = (1 + std::sqrt(5.0)) / 2;
    double l = a, r = b;
    double x1 = r - (r - l) / phi;
    double x2 = l + (r - l) / phi;
    double f1 = f(x1), f2 = f(x2);
    while (r - l > eps) {
        hist.push_back((l + r) / 2);
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
    hist.push_back((l + r) / 2);
    return hist;
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
    double f1 = f(x1), f2 = f(x2);
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

// Метод Фибоначчи с логированием
std::vector<double> fibonacci_history(const std::function<double(double)>& f, double a, double b, double eps) {
    std::vector<long long> F = {1, 1};
    while (F.back() < (b - a) / eps) {
        F.push_back(F[F.size() - 1] + F[F.size() - 2]);
    }
    int N = F.size() - 1;
    double l = a, r = b;
    int k = 1;
    double x1 = l + double(F[N - 2]) / F[N] * (r - l);
    double x2 = l + double(F[N - 1]) / F[N] * (r - l);
    double f1 = f(x1), f2 = f(x2);
    std::vector<double> hist;
    while (k < N - 1) {
        hist.push_back((l + r) / 2);
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
    hist.push_back((l + r) / 2);
    return hist;
}

#ifndef BENCHMARK_MODE
int main() {
    // Пример функции, её можно заменить на любую другую
    auto f = [](double x) {
        return x * x + 4 * std::sin(x);
    };

    double a, b, eps;
    std::cout << "Введите начальный интервал [a b]: ";
    if (!(std::cin >> a >> b)) return 0;
    std::cout << "Введите требуемую точность: ";
    if (!(std::cin >> eps)) return 0;

    // Сохраняем параметры для бенчмарка
    std::ofstream params("optimization_params.txt");
    params << a << " " << b << " " << eps;
    params.close();

    // Сохраняем историю для каждого метода
    auto hist_dicho = dichotomy_history(f, a, b, eps);
    std::ofstream fd("dichotomy_hist.txt");
    for (auto x : hist_dicho) fd << x << "\n";
    fd.close();

    auto hist_golden = goldenRatio_history(f, a, b, eps);
    std::ofstream fg("golden_hist.txt");
    for (auto x : hist_golden) fg << x << "\n";
    fg.close();

    auto hist_fib = fibonacci_history(f, a, b, eps);
    std::ofstream ff("fibonacci_hist.txt");
    for (auto x : hist_fib) ff << x << "\n";
    ff.close();

    double x_dicho = hist_dicho.back();
    std::cout << "Метод дихотомии: x* = " << x_dicho
              << ", f(x*) = " << f(x_dicho) << std::endl;

    double x_golden = hist_golden.back();
    std::cout << "Метод золотого сечения: x* = " << x_golden
              << ", f(x*) = " << f(x_golden) << std::endl;

    double x_fib = hist_fib.back();
    std::cout << "Метод Фибоначчи: x* = " << x_fib
              << ", f(x*) = " << f(x_fib) << std::endl;

    return 0;
}
#endif