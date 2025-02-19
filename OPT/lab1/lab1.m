%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ЛАБОРАТОРНАЯ РАБОТА 1 (ПОЛНАЯ, ВАРИАНТ 7, БЕЗ ВВОДА ПОЛЬЗОВАТЕЛЯ)
% Пункт 1.4.2:
% - Используются уже зафиксированные A, B, n=7
% - Выполняются все пункты, включая п.8 (главные миноры, алгебраические дополнения)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc;
close all;
clear all;

%------------------------ ВАРИАНТ 7: Исходные данные -----------------
n = 7;  % ЖЁСТКО зашитый номер варианта

A = [16 17 16 21 22;
     18 15 14 17 16;
     17 22 17 19 20;
     16 17 24 18 17;
     21 22 21 20 14];

B = [120; 102; 138; 146; 117];

disp('=== Лабораторная работа 1, Вариант 7 ===');
disp('Матрица A:');
disp(A);

disp('Матрица B:');
disp(B);

%------------------------ Шаг 2. Транспонирование -----------------
At = A';
Bt = B';

disp('Транспонированная матрица A:');
disp(At);
disp('Транспонированная матрица B:');
disp(Bt);

%------------------------ Шаг 3. Обратная матрица A -----------------
Aobr = inv(A);
disp('Обратная матрица A:');
disp(Aobr);

provA = A * Aobr;
disp('Проверка (A * Aobr) ~ единичная матрица:');
disp(provA);

%------------------------ Шаг 4. Проверка на ортогональность -----------------
Eort = At - Aobr;
disp('Проверка A на ортогональность (At - Aobr):');
disp(Eort);

%------------------------ Шаг 5. Матрица нормированных коeff. C=(Bt) -----------------
C = (Bt - min(Bt(:))) / (max(Bt(:)) - min(Bt(:)));
disp('Матрица нормированных коэффициентов C:');
disp(C);

%------------------------ Шаг 6. Умножение матриц -----------------
Fcb = C * B;   % (1×5)*(5×1) => скаляр
Fbc = B * C;   % (5×1)*(1×5) => (5×5)

disp('Результат умножения (C*B):');
disp(Fcb);
disp('Результат умножения (B*C):');
disp(Fbc);

%------------------------ Шаг 7. Определители -----------------
OFbc = det(Fbc);
OA   = det(A);

disp('Определитель (B*C):');
disp(OFbc);
disp('Определитель (A):');
disp(OA);

%------------------------ Шаг 8. Главные миноры + алгебраические дополнения -----------------
disp('==== Шаг 8: Главные (диагональные) миноры матрицы A ====');
nA = size(A,1); % =5
principalMinors = zeros(nA,1);

for kOrder=1:nA
    principalMinors(kOrder) = det(A(1:kOrder,1:kOrder));
end

disp('Главные (угловые) миноры (порядки 1..5):');
disp(principalMinors);

% Алгебраические дополнения = кофакторы
% A_sub = A без (i-й строки, j-й столбца)
cofactorMatrix = zeros(nA,nA);
for i = 1:nA
    for j = 1:nA
        A_sub = A([1:i-1 i+1:nA],[1:j-1 j+1:nA]);
        cofactorMatrix(i,j) = ((-1)^(i+j)) * det(A_sub);
    end
end

disp('Матрица алгебраических дополнений (кофакторы) A:');
disp(cofactorMatrix);

%------------------------ Шаг 9. Решение СЛАУ методом Гаусса -----------------
disp('==== Решение СЛАУ Ax=B методом Гаусса ====');
AGs = rref([A B]);
rSize = size(AGs);
XGs = AGs(:, rSize(2));

disp('Решение (XGs):');
disp(XGs);

EpsGs = A*XGs - B;
disp('Проверка решения (A*X - B):');
disp(EpsGs);

%------------------------ Шаг 10. Решение СЛАУ (обратная матрица) -----------
disp('==== Решение СЛАУ Ax=B методом обратной матрицы ====');
Xom = Aobr * B;
disp('Решение (Xom):');
disp(Xom);

Epsom = A*Xom - B;
disp('Проверка решения (A*X - B):');
disp(Epsom);

%------------------------ Шаг 11. Функция принадлежности -----------------
x = linspace(0, 10, 100);
y = sin(x);

figure;
plot(x, y, 'b', 'LineWidth', 2);
xlabel('x');
ylabel('y');
title('График функции принадлежности');
grid on;

%------------------------ Шаг 12. Целевая функция V1, V2 (граф.) -----------
% n=7, используем те же формулы
k = round(((32 - n)/(41 - n)) * n);
w = round((n - k + 6)/(n + 1));
t = -4*pi : 0.1 : 3*pi;

V1 = k*cos(w*t) + (n/(n+3)) * cos(3*w*t);
V2 = k/2 + w*t - 1;

figure;
plot(t, V1, 'b', 'LineWidth', 2);
hold on;
plot(t, V2, 'g', 'LineWidth', 2);
xlabel('t');
ylabel('F(t)');
title('Графическое решение целевой функции');
grid on;
hold off;

%------------------------ Сохраняем в текстовый файл (пример) -------------
f_stud = fopen('Lab_rabota_1_stud_N19.txt','wt');
fprintf(f_stud, '=== Лаб. работа 1, вариант 7 ===\n\n');

fprintf(f_stud, 'Матрица A\n');
dlmwrite(f_stud, A, '\t');
fprintf(f_stud, '\nМатрица B\n');
dlmwrite(f_stud, B, '\t');
fprintf(f_stud, '\nТранспонированная матрица A\n');
dlmwrite(f_stud, At, '\t');
fprintf(f_stud, '\nТранспонированная матрица B\n');
dlmwrite(f_stud, Bt, '\t');

fprintf(f_stud, '\nОбратная матрица A\n');
dlmwrite(f_stud, Aobr, '\t', "precision","%3.5e");

fprintf(f_stud, '\nПроверка A*Aobr\n');
dlmwrite(f_stud, provA, '\t', "precision","%3.3e");

fprintf(f_stud, '\nПроверка ортогональности (At-Aobr)\n');
dlmwrite(f_stud, Eort, '\t', "precision","%3.3f");

fprintf(f_stud, '\nМатрица нормир. коэфф. C\n');
dlmwrite(f_stud, C, '\t', "precision","%3.3g");

fprintf(f_stud, '\nC*B= %f\n', Fcb);
fprintf(f_stud, 'B*C => det= %f\n', OFbc);
fprintf(f_stud, 'det(A)= %f\n\n', OA);

fprintf(f_stud, 'Главные миноры A:\n');
dlmwrite(f_stud, principalMinors, '\t');

fprintf(f_stud, '\nМатрица алгебр. дополнений (кофакторы):\n');
dlmwrite(f_stud, cofactorMatrix, '\t', "precision","%3.3g");

fprintf(f_stud, '\nРешение СЛАУ (Гаусс):\n');
dlmwrite(f_stud, XGs, '\t', "precision","%3.3g");
fprintf(f_stud, 'Проверка (A*XGs-B):\n');
dlmwrite(f_stud, EpsGs, '\t', "precision","%3.3g");

fprintf(f_stud, '\nРешение СЛАУ (обратная матрица):\n');
dlmwrite(f_stud, Xom, '\t', "precision","%3.3g");
fprintf(f_stud, 'Проверка (A*Xom-B):\n');
dlmwrite(f_stud, Epsom, '\t', "precision","%3.3g");

fprintf(f_stud, '\nПараметры для целевой функции:\n');
fprintf(f_stud, 'n= %d, k= %d, w= %d\n', n, k, w);

fclose(f_stud);

%------------ Чтобы окна графики не закрывались сразу ---------------
waitforbuttonpress;