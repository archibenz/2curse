function prac4
  % ===== Практическая работа №4 (Octave) =====
  % Запустите командой >> prac4

  clf;
  % --- Исходные дискретные точки из методички (пример A1) ---
  x_pts  = [17 18 19 20 21 22 23 24 25];
  mu_pts = [0.1 0.2 0.5 0.8 1.0 0.95 0.7 0.6 0.3];

  x1  = 17:0.05:25;
  mu1 = interp1 (x_pts, mu_pts, x1, "linear");

  fig1 = figure (1);
  plot (x1, mu1, "b", "LineWidth", 2);
  hold on;
  plot (x_pts, mu_pts, "ko", "MarkerFaceColor", "w");
  xlabel ("Температура воды (°C)");
  ylabel ("\mu(x)");
  title ('"Вода для купания прохладная" — кусочно-линейная', "FontSize", 18);
  set (gca, "FontSize", 14);
  grid on;

  % --- Построение функции 2: Большое действительное число ---
  x2 = 0:0.05:25;
  mu2 = sigma(x2, 0.8, 1);

  fig2 = figure(2);
  plot(x2, mu2, 'r', 'LineWidth', 2);
  set (gca, "FontSize", 14);
  xlabel('x');
  ylabel('\mu(x)');
  title('"Большое действительное число" — σ-образная', "FontSize", 18);
  grid on;
  % Держим окна открытыми, пока пользователь их не закроет
  disp('Закройте оба графических окна, чтобы завершить программу...');
  waitfor(fig1);
  waitfor(fig2);

  % --- Локальные функции -----------------------------------

  function mu = t(x,a,b,c)
    mu = zeros(size(x));
    for i = 1:numel(x)
      xi = x(i);
      if xi <= a || xi >= c
        mu(i) = 0;
      elseif xi >= a && xi <= b
        mu(i) = (xi - a) / (b - a);
      else  % xi > b && xi <= c
        mu(i) = (c - xi) / (c - b);
      endif
    endfor
  endfunction

  function mu = sigma(x,a,b)
    mu = 1 ./ (1 + exp(-a * (x - b)));
  endfunction

endfunction