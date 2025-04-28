#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <chrono>
#include <fstream>
#include <iomanip>

// Целевая функция
double f(double x) {
    return x * x + 4 * std::sin(x);
}

// ----- Реализации методов оптимизации для бенчмарка -----

// Метод дихотомии с логированием
std::vector<double> benchmark_dichotomy(const std::function<double(double)>& f, double a, double b, double eps) {
    std::vector<double> history;
    double l = a, r = b;
    double delta = eps / 2;
    
    while (r - l > eps) {
        double x1 = (l + r - delta) / 2;
        double x2 = (l + r + delta) / 2;
        history.push_back((l + r) / 2);
        
        if (f(x1) < f(x2))
            r = x2;
        else
            l = x1;
    }
    
    history.push_back((l + r) / 2);
    return history;
}

// Метод золотого сечения с логированием
std::vector<double> benchmark_golden(const std::function<double(double)>& f, double a, double b, double eps) {
    std::vector<double> history;
    const double phi = (1 + std::sqrt(5.0)) / 2;
    double l = a, r = b;
    double x1 = r - (r - l) / phi;
    double x2 = l + (r - l) / phi;
    double f1 = f(x1), f2 = f(x2);
    
    while (r - l > eps) {
        history.push_back((l + r) / 2);
        
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
    
    history.push_back((l + r) / 2);
    return history;
}

// Метод Фибоначчи с логированием
std::vector<double> benchmark_fibonacci(const std::function<double(double)>& f, double a, double b, double eps) {
    std::vector<double> history;
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
        history.push_back((l + r) / 2);
        
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
    
    history.push_back((l + r) / 2);
    return history;
}

// Метод грубого поиска с заданным шагом
std::vector<double> benchmark_brute_force(const std::function<double(double)>& f, double a, double b, double h) {
    std::vector<double> history;
    
    // Инициализируем минимум первой точкой
    double x_min = a;
    double f_min = f(a);
    history.push_back(x_min);
    
    // Перебираем все точки с шагом h
    for (double x = a + h; x <= b; x += h) {
        double f_val = f(x);
        
        // Если нашли точку с меньшим значением, обновляем минимум
        if (f_val < f_min) {
            f_min = f_val;
            x_min = x;
            history.push_back(x_min);
        }
    }
    
    return history;
}

// Сохранение истории в CSV-файл
void save_to_csv(const std::vector<double>& history, const std::string& filename) {
    std::ofstream out(filename);
    out << "x_value\n";
    for (double x : history) {
        out << x << "\n";
    }
    out.close();
}

int main() {
    // Параметры оптимизации - используем те же, что вводил пользователь в основной программе
    // Чтение значений из файла конфигурации, если он существует
    double a = -5.0, b = 5.0, eps = 1e-4;
    
    // Проверяем, существует ли файл с настройками
    std::ifstream config("optimization_params.txt");
    if (config.is_open()) {
        config >> a >> b >> eps;
        config.close();
        std::cout << "Загружены параметры из файла: a=" << a << ", b=" << b << ", eps=" << eps << std::endl;
    }
    
    double h = eps / 10.0;  // Шаг для метода brute force
    
    std::cout << "Бенчмарк для f(x) = x² + 4⋅sin(x) на интервале [" 
              << a << ", " << b << "] с точностью " << eps << std::endl;
    
    using clock = std::chrono::high_resolution_clock;
    std::vector<double> history;
    
    // 1. Brute Force
    auto start = clock::now();
    history = benchmark_brute_force(f, a, b, h);
    auto end = clock::now();
    auto brute_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    save_to_csv(history, "brute_hist.csv");
    
    std::cout << "Brute Force:\n";
    std::cout << "  x* = " << std::setprecision(8) << history.back() << ", f(x*) = " << f(history.back()) << "\n";
    std::cout << "  Итераций: " << history.size() << "\n";
    std::cout << "  Время: " << brute_time << " мкс\n\n";
    
    // 2. Dichotomy
    start = clock::now();
    history = benchmark_dichotomy(f, a, b, eps);
    end = clock::now();
    auto dicho_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    save_to_csv(history, "dichotomy_hist.csv");
    
    std::cout << "Дихотомия:\n";
    std::cout << "  x* = " << std::setprecision(8) << history.back() << ", f(x*) = " << f(history.back()) << "\n";
    std::cout << "  Итераций: " << history.size() << "\n";
    std::cout << "  Время: " << dicho_time << " мкс\n\n";
    
    // 3. Golden Ratio
    start = clock::now();
    history = benchmark_golden(f, a, b, eps);
    end = clock::now();
    auto golden_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    save_to_csv(history, "golden_hist.csv");
    
    std::cout << "Золотое сечение:\n";
    std::cout << "  x* = " << std::setprecision(8) << history.back() << ", f(x*) = " << f(history.back()) << "\n";
    std::cout << "  Итераций: " << history.size() << "\n";
    std::cout << "  Время: " << golden_time << " мкс\n\n";
    
    // 4. Fibonacci
    start = clock::now();
    history = benchmark_fibonacci(f, a, b, eps);
    end = clock::now();
    auto fib_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    save_to_csv(history, "fibonacci_hist.csv");
    
    std::cout << "Метод Фибоначчи:\n";
    std::cout << "  x* = " << std::setprecision(8) << history.back() << ", f(x*) = " << f(history.back()) << "\n";
    std::cout << "  Итераций: " << history.size() << "\n";
    std::cout << "  Время: " << fib_time << " мкс\n\n";
    
    // Сравнение времени
    std::cout << "Ускорение относительно Brute Force:\n";
    std::cout << "  Дихотомия: " << std::fixed << std::setprecision(2) 
              << (double)brute_time / dicho_time << "x\n";
    std::cout << "  Золотое сечение: " << std::fixed << std::setprecision(2) 
              << (double)brute_time / golden_time << "x\n";
    std::cout << "  Фибоначчи: " << std::fixed << std::setprecision(2) 
              << (double)brute_time / fib_time << "x\n";
    
    return 0;
}