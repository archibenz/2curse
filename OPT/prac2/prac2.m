clc;
clear;

% Загружаем данные
load("results.mat");

% Выводим заголовок
disp("Практическая работа 2");
disp("======================");
fprintf("Вариант: 10\n");
fprintf("Группа: 3\n");
fprintf("ФИО: Коломиец Александр, Морозов Михаил\n\n");

% Вывод данных по пунктам
disp("1. Выписаны исходные данные:");
fprintf("   Целевая функция: max(11x1 + 18x2 + 7x3 + 13x4 + x5 + 14x6 + 5x7)\n");
fprintf("   Ограничения A:\n");
disp(A);
fprintf("   Вектор B:\n");
disp(B);

disp("2. Матрица ограничений A записана.\n");
disp("3. Вектор B записан.\n");

disp("4. Ограничения приведены к уравнениям:");
disp(A);

fprintf("5. Определен ранг базисных переменных: m = %d\n\n", rank(A));

disp("6. Определены матрицы D и S:");
disp("D =");
disp(A(:, 1:rank(A)));
disp("S =");
disp(A(:, rank(A)+1:end));

disp("7. Найдена обратная матрица D⁻¹:");
disp(inv(A(:, 1:rank(A))));

disp("8. Вычислены коэффициенты βi:");
beta = inv(A(:, 1:rank(A))) * B;
disp(beta);

disp("9. Вычислены коэффициенты αij:");
alpha = inv(A(:, 1:rank(A))) * A(:, rank(A)+1:end);
disp(alpha);

% Формируем уравнение в базисных переменных
disp("10. Записано уравнение в базисных переменных.");
equation_str = "   xБ = [ ";
for i = 1:length(beta)
    equation_str = strcat(equation_str, sprintf("%.3f ", beta(i)));
end
equation_str = strcat(equation_str, "] + [ ");

for i = 1:size(alpha, 1)
    equation_str = strcat(equation_str, sprintf("%.3f ", alpha(i, :)));
    if i < size(alpha, 1)
        equation_str = strcat(equation_str, "; ");
    end
end
equation_str = strcat(equation_str, "] * xH");
disp(equation_str);
