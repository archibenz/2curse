% Пример Лабораторная работа
clc;
close all;
clear all;

% Исходные матрицы
Aish = [3 4 3 8 9; 5 2 1 4 3; 4 9 4 6 7; 3 4 11 5 4; 8 9 8 7 1];
Bish = [61; 43; 79; 87; 58];

% Ввод номера варианта
disp('Введите номер варианта [1 . . . 30]');
n = input('n=');
if n <= 0
    n = 1;
elseif n > 30
    n = 30;
end

disp('Исходные данные варианта');
disp(n);

% Вычисление A и B
A = Aish + (2 * n - 1);
B = Bish + (9 * n - 4);

% Вывод матриц
disp('Матрица A:');
disp(A);

disp('Матрица B:');
disp(B);

% Транспонирование матриц
Bt = B';
At = A';

disp('Транспонированные матрицы A и B:');
disp(At);
disp(Bt);

% Вычисление обратной матрицы A
Aobr = inv(A);
provA = A * Aobr;

disp('Обратная матрица A:');
disp(Aobr);

disp('Проверка обратной матрицы A (A * Aobr):');
disp(provA);

% Проверка ортогональности
Eort = At - Aobr;
disp('Проверка матрицы A на ортогональность (At - Aobr):');
disp(Eort);

% Матрица нормированных коэффициентов
C = (Bt - min(Bt(:))) / (max(Bt(:)) - min(Bt(:)));
disp('Матрица нормированных коэффициентов C:');
disp(C);

% Умножение матриц
Fcb = C * B;  % Исправлено
Fbc = B * C;   % Исправлено

disp('Результат умножения C * B:');
disp(Fcb);

disp('Результат умножения B * C:');
disp(Fbc);

% Определители
OFbc = det(Fbc);
OA = det(A);

disp('Определитель матрицы B * C:');
disp(OFbc);

disp('Определитель матрицы A:');
disp(OA);

% Минор матрицы A
M12 = A(2:5, [1, 3:5]);
M12_Fbc = det(M12);

disp('Минор [2:5, 1, 3:5] матрицы A:');
disp(M12_Fbc);

% Решение СЛАУ методом Гаусса
AGs = rref([A B]);
XGs = AGs(:, end);
EpsGs = A * XGs - B;

disp('Решение СЛАУ методом Гаусса:');
disp(XGs);

disp('Проверка решения СЛАУ (Ax - B):');
disp(EpsGs);

% Решение СЛАУ методом обратной матрицы
Xom = inv(A) * B;
Epsom = A * Xom - B;

disp('Решение СЛАУ методом обратной матрицы:');
disp(Xom);

disp('Проверка решения СЛАУ (Ax - B):');
disp(Epsom);

% Графическое представление функции принадлежности
x = linspace(0, 10, 100);
y = sin(x);

figure;
plot(x, y, 'b', 'LineWidth', 2);
xlabel('x');
ylabel('y');
title('График функции принадлежности');
grid on;

% Графическое решение целевой функции
t = -4*pi:0.1:3*pi;
k = round(((32 - n) / (41 - n)) * n);
w = round((n - k + 6) / (n + 1));

V1 = k * cos(w * t) + (n / (n + 3)) * cos(3 * w * t);
V2 = k / 2 + w * t - 1;

figure;
plot(t, V1, 'b', 'LineWidth', 2);
hold on;
plot(t, V2, 'g', 'LineWidth', 2);
xlabel('t');
ylabel('F(t)');
title('Графическое решение целевой функции');
grid on;
hold off;
waitforbuttonpress;