clc;
clear;

% Загружаем данные из solver.m
load("results.mat");

% Вывод заголовка
disp("Практическая работа 2");
disp("======================");
fprintf("Вариант: 10\n");
fprintf("Группа: 3\n");
fprintf("ФИО: Коломиец Александр, Морозов Михаил\n\n");

% Вывод исходных данных
disp("1. Выписаны исходные данные:");
fprintf("   Целевая функция: max(11x1 + 18x2 + 7x3 + 13x4 + x5 + 14x6 + 5x7)\n");
fprintf("   Ограничения A:\n");
disp(A);
fprintf("   Вектор B:\n");
disp(B);

disp("2. Ограничения приведены к уравнениям:");
disp(A);

% Определяем размерности
m = rank(A); % Ранг матрицы (количество базисных переменных)
n = size(A, 2); % Общее число переменных

fprintf("3. Определен ранг базисных переменных: m = %d\n\n", m);

% Разделение A на D и S
disp("4. Определены матрицы D и S:");
D = A(:, 1:m); % Берем первые m столбцов как D
S = A(:, m+1:end); % Остальные столбцы — S
disp("D =");
disp(D);
disp("S =");
disp(S);

% Обратная матрица D⁻¹
disp("5. Найдена обратная матрица D⁻¹:");
D_inv = inv(D);
disp(D_inv);

% Вычисление β (D⁻¹ * B)
disp("6. Вычислены коэффициенты βi:");
original_beta = D_inv * B;

% Создаем новый β с удвоением отрицательных значений
beta = [];
rows_to_duplicate = [];

for i = 1:length(original_beta)
    if original_beta(i) < 0
        % Если β < 0, заменяем его на два новых значения
        beta = [beta; abs(original_beta(i)); 2 * abs(original_beta(i))];
        rows_to_duplicate = [rows_to_duplicate; i]; % Запоминаем, какие строки дублировали
    else
        beta = [beta; original_beta(i)];
    end
end

disp(beta);

% Обновляем матрицу α (D⁻¹ * S) с учетом новых строк
disp("7. Вычислены коэффициенты αij:");
alpha = D_inv * S;

% Дублируем соответствующие строки в α
new_alpha = [];
for i = 1:size(alpha, 1)
    if ismember(i, rows_to_duplicate)
        % Если строка была в β как отрицательная, добавляем ее дважды с дублированными значениями
        new_alpha = [new_alpha; abs(alpha(i, :)); 2 * abs(alpha(i, :))];
    else
        new_alpha = [new_alpha; alpha(i, :)];
    end
end
alpha = new_alpha;

disp(alpha);

% Развернутое уравнение в базисных переменных
disp("8. Развернутое уравнение в базисных переменных:");

fprintf("\nСистема уравнений в явном виде:\n");

for i = 1:length(beta)
    equation_str = sprintf("   x%d = %.3f", i, beta(i)); % Левая часть уравнения
    if size(alpha, 2) > 0
        equation_str = strcat(equation_str, " - ("); % Открываем скобку для минус α * X_H
        for j = 1:size(alpha, 2)
            sign = " - "; % По умолчанию минус
            if alpha(i, j) < 0
                sign = " + "; % Если коэффициент отрицательный, делаем +
            end
            equation_str = strcat(equation_str, sprintf("%s%.3f * x%d", sign, abs(alpha(i, j)), m + j));
        end
        equation_str = strcat(equation_str, ")"); % Закрываем скобку
    end
    disp(equation_str);
end

disp("\nМатричная форма записи:");
fprintf("   xБ = [");
fprintf("%.3f, ", beta(1:end-1));
fprintf("%.3f] ", beta(end)); % Последний без запятой
fprintf(" - [");

for i = 1:size(alpha, 1)
    fprintf("[");
    fprintf("%.3f, ", alpha(i, 1:end-1));
    fprintf("%.3f] ", alpha(i, end)); % Последний без запятой
    if i < size(alpha, 1)
        fprintf(";\n        ");
    end
end
fprintf("] * xH\n\n");

% Выводим исправленное базисное решение
disp("\n9. Базисное решение системы (при X_H = 0):");

X = zeros(n + length(rows_to_duplicate), 1);
X(1:length(beta)) = beta;  % Заполняем базисные переменные значениями β

fprintf("   X = (");
fprintf("%.3f, ", X(1:length(beta)));  % Вывод базисных переменных
fprintf(repmat("0, ", 1, n - length(beta))); % Добавляем нули
fprintf("\b\b)\n");  % Убираем последнюю запятую