import math
import matplotlib.pyplot as plt
import numpy as np  # для построения гладкой кривой

def main():
    # Задайте номер варианта здесь (при необходимости)
    variant = 7  
    # Если для вашего варианта нужно менять выборку, измените массив data ниже.
    data = [
        0.7, 0.5, 0.4, 0.6, 0.3, 1.4, 1.4, 0.6, 1.9, 2.0,
        0.1, 0.1, 1.2, 0.7, 0.4, 0.7, 0.4, 0.1, 0.4, 0.5,
        1.4, 0.5, 1.2, 0.4, 0.4, 0.6, 0.2, 0.4, 0.3, 0.3,
        0.1, 0.3, 0.3, 1.0, 1.1, 1.9, 0.1, 1.5, 1.1, 0.4,
        0.5, 0.7, 0.6, 1.5, 0.2, 0.2, 0.1, 1.0, 1.7, 0.1
    ]

    # 1) Вариационный ряд (отсортированные данные)
    sorted_data = sorted(data)

    # 2) Минимальный и максимальный элементы
    min_val = min(sorted_data)
    max_val = max(sorted_data)

    # 3) Объём выборки
    n = len(data)

    # 4) Размах выборки
    data_range = max_val - min_val

    # 5) Число интервалов l - теперь фиксированное число (5)
    l = 5

    # 6) Длина интервала
    h = data_range / l

    # 7) Границы интервалов
    boundaries = [min_val + i * h for i in range(l)]
    boundaries.append(max_val)

    # 8) Интервалы (форматируем строки)
    intervals = [f"[{boundaries[i]:.3f}; {boundaries[i+1]:.3f})" for i in range(l-1)]
    intervals.append(f"[{boundaries[-2]:.3f}; {boundaries[-1]:.3f}]")

    # 9) Абсолютные частоты
    freq = [0] * l
    for value in sorted_data:
        for j in range(l):
            left, right = boundaries[j], boundaries[j+1]
            if j < l - 1:
                if left <= value < right:
                    freq[j] += 1
                    break
            else:
                if left <= value <= right:
                    freq[j] += 1
                    break

    # 10) Относительные частоты
    rel_freq = [f / n for f in freq]

    # 11) Накопленные частоты
    cum_freq = [sum(rel_freq[:i+1]) for i in range(l)]

    # 12) Середины интервалов
    midpoints = [(boundaries[i] + boundaries[i+1]) / 2 for i in range(l)]

    # --- Вывод всех рассчитанных значений ---
    print("\nВариационный ряд (отсортированные данные):")
    print(sorted_data)
    print(f"\nМинимальный элемент: {min_val}")
    print(f"Максимальный элемент: {max_val}")
    print(f"Объём выборки n: {n}")
    print(f"Размах выборки: {data_range:.3f}")
    print(f"Число интервалов l: {l}")
    print(f"\nДлина интервала (h) = {h:.3f}")

    print("\nГраницы интервалов (a_i):")
    for i, b in enumerate(boundaries):
        print(f"a{i} = {b:.3f}")

    print("\nИнтервалы:")
    for i, iv in enumerate(intervals, 1):
        print(f"I{i} = {iv}")

    print("\nЧисло выборочных значений в каждом интервале:")
    for i, val in enumerate(freq, 1):
        print(f"n{i} = {val}")
    print(f"Контроль: сумма n_i = {sum(freq)}")

    print("\nЧастоты интервального ряда (p_i*):")
    for i, val in enumerate(rel_freq, 1):
        print(f"p{i}* = {val:.3f}")
    print(f"Контроль: сумма p_i* = {sum(rel_freq):.3f}")

    print("\nНакопленные частоты z_i:")
    for i, val in enumerate(cum_freq, 1):
        print(f"z{i} = {val:.3f}")

    print("\nСередины интервалов x_i*:")
    for i, mp in enumerate(midpoints, 1):
        print(f"x{i}* = {mp:.3f}")

    print("\nИнтервальный статистический ряд:")
    print(" I_i   |   x_i*    |   n_i   |  p_i*   |  z_i ")
    print("----------------------------------------------")
    for i in range(l):
        print(f" I{i+1:<2}  | {midpoints[i]:8.3f} | {freq[i]:7d} | {rel_freq[i]:7.3f} | {cum_freq[i]:5.3f}")
    print("----------------------------------------------")
    print(f"  Σ    |     -     | {sum(freq):7d} | {sum(rel_freq):7.3f} | {sum(cum_freq):5.3f}")

    # --- Построение графиков ---
    # Вычисление высот гистограммы
    heights = [rel_freq[i] / h for i in range(l)]
    # Для теоретической кривой
    def normal_pdf(x, mu, sigma):
        return (1.0 / (sigma * math.sqrt(2 * math.pi))) * math.exp(-((x - mu) ** 2) / (2 * sigma ** 2))

    # Точечные оценки
    sample_mean = sum(midpoints[i] * rel_freq[i] for i in range(l))
    sample_var = sum(((midpoints[i] - sample_mean) ** 2) * rel_freq[i] for i in range(l))
    corrected_var = (n / (n - 1)) * sample_var
    corrected_std = math.sqrt(corrected_var)

    # Для теоретической кривой построим x-сетку от min_val до max_val
    x_grid = np.linspace(min_val, max_val, 200)
    y_grid = [normal_pdf(x, sample_mean, corrected_std) for x in x_grid]

    # Создаем фигуру с 3 подграфиками
    fig, axs = plt.subplots(3, 1, figsize=(10, 18))

    # График 1: Эмпирическая функция распределения
    axs[0].step([-math.inf] + midpoints, [0] + cum_freq, where='post', label="Эмпирическая функция $F_n^*(x)$", linewidth=2)
    axs[0].scatter(midpoints, cum_freq, color='red', zorder=3)
    axs[0].set_xlabel("x")
    axs[0].set_ylabel("$F_n^*(x)$")
    axs[0].set_title("Эмпирическая функция распределения")
    axs[0].grid()
    axs[0].legend()

    # График 2: Гистограмма и полигон частот
    axs[1].bar(midpoints, heights, width=h, edgecolor='black', alpha=0.6, label="Гистограмма")
    axs[1].plot(midpoints, heights, marker='o', color='red', label="Полигон частот", linewidth=2)
    axs[1].set_xlabel("x")
    axs[1].set_ylabel("$f_n^*(x)$")
    axs[1].set_title("Гистограмма и полигон частот")
    axs[1].grid()
    axs[1].legend()

    # График 3: Гистограмма, полигон частот и теоретическая кривая
    axs[2].bar(midpoints, heights, width=h, edgecolor='black', alpha=0.6, label="Гистограмма")
    axs[2].plot(midpoints, heights, marker='o', color='red', linewidth=2, label="Полигон частот")
    axs[2].plot(x_grid, y_grid, 'g-', linewidth=2, label="Теоретическая кривая N( x̄ , s̄ )")
    axs[2].set_xlabel("x")
    axs[2].set_ylabel("f(x)")
    axs[2].set_title("Гистограмма, полигон частот и теоретическая кривая N")
    axs[2].grid()
    axs[2].legend()

    plt.tight_layout()
    plt.show()

    # ----------------------------------------------------
    #   СТАРЫЕ ДОПОЛНЕНИЯ (точечные оценки) НЕ МЕНЯЕМ
    # ----------------------------------------------------
    # (Допустим, здесь у нас уже были выборочное среднее, дисперсия и т.д.)
    # Медиана:
    median_val = (sorted_data[24] + sorted_data[25]) / 2

    # Асимметрия и эксцесс:
    skew_num = sum(((midpoints[i] - sample_mean) ** 3) * rel_freq[i] for i in range(l))
    kurt_num = sum(((midpoints[i] - sample_mean) ** 4) * rel_freq[i] for i in range(l))
    sample_skew = skew_num / (corrected_std ** 3)
    sample_kurt = (kurt_num / (corrected_std ** 4)) - 3

    print("\n--- Точечные статистические оценки ---")
    print(f"Выборочное среднее (x̄) = {sample_mean:.3f}")
    print(f"Выборочная дисперсия (s^2) = {sample_var:.3f}")
    print(f"Исправленная дисперсия (s̄²) = {corrected_var:.3f}")
    print(f"Исправленное СКВО (s̄) = {corrected_std:.3f}")
    print(f"Выборочная медиана (μ*) = {median_val:.3f}")
    print(f"Выборочная асимметрия (A*) = {sample_skew:.3f}")
    print(f"Выборочный эксцесс (E*) = {sample_kurt:.3f}")

    # --- Теоретическая плотность нормального распределения ---
    print("\n--- Теоретическая плотность нормального распределения ---")
    theor_values = []
    for i, mp in enumerate(midpoints, 1):
        f_val = normal_pdf(mp, sample_mean, corrected_std)
        theor_values.append(f_val)
        print(f"f(x{i}*) = {f_val:.3f}")

if __name__ == "__main__":
    main()