// main.c
#include <stdio.h>
#include <stdint.h> // Для использования int64_t и uint64_t
#include <limits.h>

// Глобальные переменные для обмена данными между Си и ASM
// Signed int
int64_t a_signed, b_signed; // Исходные данные
int64_t x_signed;           // Результат

// Unsigned int
uint64_t a_unsigned, b_unsigned; // Исходные данные
uint64_t x_unsigned;             // Результат

// Прототипы функций ASM
void signed_int();     // Функция для signed int
void unsigned_int();   // Функция для unsigned int

int main() {
    int choice;
    printf("Выберите тип данных:\n");
    printf("1. Signed int\n");
    printf("2. Unsigned int\n");
    printf("Ваш выбор: ");
    if (scanf("%d", &choice) != 1) {
        printf("Неверный выбор.\n");
        return 1;
    }

    if (choice == 1) {
        // Ввод значений для signed int
        printf("Введите целое число a (signed int): ");
        while (scanf("%lld", &a_signed) != 1) {
            printf("Неверный ввод. Пожалуйста, введите целое число a: ");
            while (getchar() != '\n');
        }

        printf("Введите целое число b (signed int): ");
        while (scanf("%lld", &b_signed) != 1) {
            printf("Неверный ввод. Пожалуйста, введите целое число b: ");
            while (getchar() != '\n');
        }

        // Проверка на деление на ноль при a > b
        if ((a_signed > b_signed) && (b_signed == 0)) {
            printf("Ошибка: Деление на ноль при a > b.\n");
            return 1;
        }

        // Вызов ASM-функции для signed int
        signed_int();

        // Вывод результата
        printf("Результат X (signed int): %lld\n", x_signed);
    } else if (choice == 2) {
        // Ввод значений для unsigned int
        printf("Введите целое число a (unsigned int): ");
        while (scanf("%llu", &a_unsigned) != 1) {
            printf("Неверный ввод. Пожалуйста, введите целое число a: ");
            while (getchar() != '\n');
        }

        printf("Введите целое число b (unsigned int): ");
        while (scanf("%llu", &b_unsigned) != 1) {
            printf("Неверный ввод. Пожалуйста, введите целое число b: ");
            while (getchar() != '\n');
        }

        // Проверка на деление на ноль при a > b
        if ((a_unsigned > b_unsigned) && (b_unsigned == 0)) {
            printf("Ошибка: Деление на ноль при a > b.\n");
            return 1;
        }

        // Вызов ASM-функции для unsigned int
        unsigned_int();

        // Вывод результата
        printf("Результат X (unsigned int): %llu\n", x_unsigned);
    } else {
        printf("Неверный выбор.\n");
        return 1;
    }

    return 0;
}
