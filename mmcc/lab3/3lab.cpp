#include <iostream>
#include <cmath>  // для функций pow и tgamma

using namespace std;

// Функция для вычисления факториала
double factorial(int n) {
    return tgamma(n + 1);  // tgamma(n+1) вычисляет n!
}

int main() {
    double a;
    int v;
    char choice;  // Переменная для хранения ответа пользователя

    do {
        // Ввод параметров a и v
        cout << "Введите значение a: ";
        cin >> a;
        cout << "Введите значение v: ";
        cin >> v;
        
        // Вычисляем числитель: a^v / v!
        double numerator = pow(a, v) / factorial(v);
        
        // Вычисляем знаменатель: сумма от k=0 до v (a^k / k!)
        double denominator = 0;
        for (int k = 0; k <= v; k++) {
            denominator += pow(a, k) / factorial(k);
        }
        
        // Вычисляем p
        double p = numerator / denominator;
        
        // Выводим результат
        cout << "Результат p: " << p << endl;
        
        // Спрашиваем пользователя, хочет ли он повторить вычисления
        cout << "Хотите повторить вычисления с другими данными? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');  // Повторять, если пользователь ввел 'y' или 'Y'
    
    return 0;
}

// g++ -c -g -o execfile.o 3lab.cpp
// objdump -d -M intel execfile.o > disassembly.asm