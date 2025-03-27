#include <stdio.h>

// Переменные для signed char
signed char a_char, b_char, c_char;
int numerator_char, denominator_char, result_char;

// Variables for unsigned short (16-bit)
unsigned short a_uint, b_uint, c_uint;
int numerator_uint, denominator_uint, result_uint;
// Прототипы функций
void compute_signed_char();
void compute_unsigned_int();

int main() {
    int choice;

    // Ввод выбора типа переменных
    printf("Выберите тип переменных:\n");
    printf("0 - signed char (8 бит)\n");
    printf("1 - unsigned int (16 бит)\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    while (choice != 1 && choice != 0) {
        printf("Неверный ввод! Повторите снова\n");
        scanf("%d", &choice);
    }

    if (choice == 0) {
        // Работа с signed char (8 бит)
        printf("Введите значения для знаковых 8-битных переменных (от -128 до 127):\n");
        printf("Введите a: ");
        scanf("%hhd", &a_char);
        printf("Введите b: ");
        scanf("%hhd", &b_char);
        printf("Введите c: ");
        scanf("%hhd", &c_char);

        while (a_char == 0) {
            printf("Ошибка: a не может быть равно 0. Введите a снова: ");
            scanf("%hhd", &a_char);
        }

        // Вычисления на C
        numerator_char = (b_char * c_char - 8 / a_char);
        denominator_char = (31 + b_char - 1);

        if (denominator_char == 0) {
            printf("Ошибка: Знаменатель равен 0. Невозможно выполнить деление.\n");
            return 1;
        }

        result_char = numerator_char / denominator_char;

        printf("\nРезультаты для signed char (C):\n");
        printf("Числитель: %d, Знаменатель: %d, Результат: %d\n", numerator_char, denominator_char, result_char);

        // Вызов ассемблерной функции
        compute_signed_char();

        // Вывод результатов ассемблерной функции
        printf("\nРезультаты для signed char (ASM):\n");
        printf("Числитель: %d, Знаменатель: %d, Результат: %d\n", numerator_char, denominator_char, result_char);

    } else if (choice == 1) {
        // Работа с unsigned int (16 бит)
        printf("Введите значения для беззнаковых 16-битных переменных (от 0 до 65535):\n");
        printf("Введите a: ");
        scanf("%hu", &a_uint);
        printf("Введите b: ");
        scanf("%hu", &b_uint);
        printf("Введите c: ");
        scanf("%hu", &c_uint);

        while (a_uint == 0) {
            printf("Ошибка: a не может быть равно 0. Введите a снова: ");
            scanf("%hu", &a_uint);
        }

        // Вычисления на C
        numerator_uint = (b_uint * c_uint - 8 / a_uint);
        denominator_uint = (31 + b_uint - 1);

        if (denominator_uint == 0) {
            printf("Ошибка: Знаменатель равен 0. Невозможно выполнить деление.\n");
            return 1;
        }

        result_uint = numerator_uint / denominator_uint;

        printf("\nРезультаты для unsigned int (C):\n");
        printf("Числитель: %d, Знаменатель: %u, Результат: %d\n", numerator_uint, denominator_uint, result_uint);

        // Вызов ассемблерной функции
        compute_unsigned_int();

        // Вывод результатов ассемблерной функции
        printf("\nРезультаты для unsigned int (ASM):\n");
        printf("Числитель: %d, Знаменатель: %u, Результат: %d\n", numerator_uint, denominator_uint, result_uint);
    }

    return 0;
}