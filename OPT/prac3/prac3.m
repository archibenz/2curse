% Практическая работа №3, вариант 7
% Принятие решения в условиях неопределенности

clc;
clear;

% Исходная матрица затрат (альтернатива х состояния среды)
V = [
  110, 100, 130, 140;
  130, 120, 120, 150;
  150, 140, 110, 160;
  160, 150, 150, 170
];

[m, n] = size(V);
disp('Матрица затрат:')
disp(V)

%% Критерий Лапласа
% Формула критерия Лапласа:
% M(ai) = (1/n) * сумма по j от 1 до n V(ai, sj)
avg_Laplace = sum(V, 2) / n;
[opt_Laplace, idx_Laplace] = min(avg_Laplace);

disp('===================================================')
disp('КРИТЕРИЙ ЛАПЛАСА')
disp('Формула: M(ai) = (1/n) * сумма по j от 1 до n V(ai, sj)')
disp(' ')
disp('Средние значения по альтернативам:')
disp(avg_Laplace')
disp(['-> Оптимальная альтернатива: a', num2str(idx_Laplace), ' со значением ', num2str(opt_Laplace)])
disp('===================================================')

%% Критерий Вальда (Минимаксный)
% Формула критерия Вальда (Минимаксного):
% Для доходов: max(min V(ai, sj))
% Для затрат: min(max V(ai, sj))
max_losses = max(V, [], 2);
[opt_Wald, idx_Wald] = min(max_losses);

disp('===================================================')
disp('КРИТЕРИЙ ВАЛЬДА')
disp('Формула: Для затрат: min(max V(ai, sj))')
disp(' ')
disp('Максимальные потери по альтернативам:')
disp(max_losses')
disp(['-> Оптимальная альтернатива: a', num2str(idx_Wald), ' со значением ', num2str(opt_Wald)])
disp('===================================================')

%% Критерий Сэвиджа (Минимальный максимальный риск)
% Формула матрицы рисков по Сэвиджу:
% r(ai, sj) = V(ai, sj) - min V(ak, sj)
% Минимальный максимальный риск: min(max r(ai, sj))
min_by_col = min(V);
risk_matrix = V - repmat(min_by_col, m, 1);
max_risks = max(risk_matrix, [], 2);
[opt_Savage, idx_Savage] = min(max_risks);

disp('===================================================')
disp('КРИТЕРИЙ СЭВИДЖА')
disp('Формула: Минимальный максимальный риск: min(max r(ai, sj))')
disp(' ')
disp('Матрица рисков:')
disp(risk_matrix)
disp('Максимальные риски по альтернативам:')
disp(max_risks')
disp(['-> Оптимальная альтернатива: a', num2str(idx_Savage), ' со значением ', num2str(opt_Savage)])
disp('===================================================')

%% Критерий Гурвица
% Формула критерия Гурвица:
% Для затрат: H(ai) = alpha * min V(ai) + (1 - alpha) * max V(ai)
alpha = 0.5; % параметр оптимизма (можно менять)
min_vals = min(V, [], 2);
max_vals = max(V, [], 2);
gurvitz = alpha * min_vals + (1 - alpha) * max_vals;
[opt_Gurvitz, idx_Gurvitz] = min(gurvitz);

disp('===================================================')
disp(['КРИТЕРИЙ ГУРВИЦА (alpha = ', num2str(alpha), ')'])
disp('Формула: H(ai) = alpha * min V(ai) + (1 - alpha) * max V(ai)')
disp(' ')
disp('min по строкам:')
disp(min_vals')
disp('max по строкам:')
disp(max_vals')
disp('Взвешенные оценки:')
disp(gurvitz')
disp(['-> Оптимальная альтернатива: a', num2str(idx_Gurvitz), ' со значением ', num2str(opt_Gurvitz)])
disp('===================================================')