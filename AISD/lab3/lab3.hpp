
#pragma once

#include <functional>
#include <vector>

// Методы оптимизации, возвращающие историю приближений
std::vector<double> dichotomy_history(const std::function<double(double)>& f, double a, double b, double eps);
std::vector<double> goldenRatio_history(const std::function<double(double)>& f, double a, double b, double eps);
std::vector<double> fibonacci_history(const std::function<double(double)>& f, double a, double b, double eps);

// Методы оптимизации, возвращающие только конечный результат
double dichotomy(const std::function<double(double)>& f, double a, double b, double eps);
double goldenRatio(const std::function<double(double)>& f, double a, double b, double eps);
double fibonacci(const std::function<double(double)>& f, double a, double b, double eps);