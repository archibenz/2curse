#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib> // Для system()

const int M = 3; // Общее количество приоритетов

// Функция для расчета времени доставки для модели M/D/1
double calculate_delivery_time_md1(double a, int K, double sigma) {
    double rho = a / M; // Интенсивность нагрузки
    double W = 0.0;

    if (K == 1) {
        for (int i = 1; i <= M; ++i) {
            W += (rho * sigma) / (1 - rho);
        }
    } else {
        W = (1 / (1 - rho)) * std::pow(1 + (sigma * sigma) / 2, -1);
        for (int i = 1; i < K; ++i) {
            W -= (rho * sigma) / (1 - rho);
        }
    }

    double T = W + a; // Время доставки
    return T;
}

int main() {
    std::vector<double> a_values;
    for (double a = 0.15; a <= 0.99; a += 0.1) {
        a_values.push_back(a); // Значения интенсивности нагрузки
    }

    double sigma = 1.0; // Пример значения для стандартного отклонения, можно изменить

    // Открытие файла для записи результатов
    std::ofstream file("results_md1.dat");
    file << "a\tPriority_1\tPriority_2\tPriority_3\n";

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "a\tPriority 1\tPriority 2\tPriority 3\n";

    // Запись результатов в файл и вывод в консоль
    for (double a : a_values) {
        std::cout << a << "\t";
        file << a;
        for (int K = 1; K <= M; ++K) {
            double T = calculate_delivery_time_md1(a, K, sigma);
            std::cout << T << "\t\t";
            file << "\t" << T;
        }
        std::cout << "\n";
        file << "\n";
    }

    file.close();

    // Создание Gnuplot-скрипта для построения графика
    std::ofstream gp_script("script_md1.gp");
    gp_script << "set terminal png size 800,600\n";
    gp_script << "set output 'delivery_time_md1.png'\n";
    gp_script << "set title 'M/D/1: Зависимость времени доставки от интенсивности нагрузки'\n";
    gp_script << "set xlabel 'Интенсивность нагрузки (a)'\n";
    gp_script << "set ylabel 'Время доставки (T)'\n";
    gp_script << "set grid\n";
    gp_script << "plot 'results_md1.dat' using 1:2 with lines title 'Priority 1', \\\n";
    gp_script << "     'results_md1.dat' using 1:3 with lines title 'Priority 2', \\\n";
    gp_script << "     'results_md1.dat' using 1:4 with lines title 'Priority 3'\n";
    gp_script.close();

    // Запуск Gnuplot для построения графика
    system("gnuplot script_md1.gp");

    std::cout << "График сохранен в файл delivery_time_md1.png\n";

    return 0;
}
