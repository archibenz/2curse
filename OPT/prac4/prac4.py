import numpy as np
import matplotlib.pyplot as plt

# ГРАФИК 1: Функция принадлежности "Вода для купания прохладная"
# Дискретные данные (вариант для первого отдыхающего):
x_points = np.array([17, 18, 19, 20, 21, 22, 23, 24, 25])
mu_points  = np.array([0.1, 0.2, 0.5, 0.8, 1.0, 0.95, 0.7, 0.6, 0.3])

# Непрерывный вектор x для построения линии функции (с линейной интерполяцией):
x_cont = np.linspace(17, 25, 200)
mu_cont = np.interp(x_cont, x_points, mu_points)

# Создаём первое окно с графиком
plt.figure(figsize=(10, 6))
plt.plot(x_cont, mu_cont, label="Непрерывная функция принадлежности", color='blue', linewidth=2)
plt.plot(x_points, mu_points, 'o', label="Дискретные значения", color='black', 
         markerfacecolor='white', markersize=8)
# Вертикальные линии для ключевых точек:
plt.axvline(x=17, color='orange', linestyle='--', label="Левая граница (17°C)")
plt.axvline(x=21, color='green', linestyle='--', label="Оптимум (21°C)")
plt.axvline(x=25, color='purple', linestyle='--', label="Правая граница (25°C)")

plt.title("Функция принадлежности: 'Вода для купания прохладная'")
plt.xlabel("Температура воды (°C)")
plt.ylabel("Функция принадлежности μ(x)")
plt.legend()
plt.grid(True)
plt.axis([16, 26, 0, 1.05])

# ГРАФИК 2: Функция принадлежности "Большое действительное число"
# Функция: μ_A(x) = 0, если x < 1, иначе (x-1)/x
x2 = np.linspace(0, 25, 250)
mu2 = np.array([0 if xi < 1 else (xi - 1) / xi for xi in x2])

# Создаём второе окно с графиком
plt.figure(figsize=(10, 6))
plt.plot(x2, mu2, label="μ_A(x) = (x-1)/x, x ≥ 1", color='red', linewidth=2)
plt.title("Функция принадлежности: 'Большое действительное число'")
plt.xlabel("x")
plt.ylabel("Функция принадлежности μ_A(x)")
plt.legend()
plt.grid(True)
plt.axis([0, 25, 0, 1.05])

# Отображаем оба графика одновременно
plt.show()