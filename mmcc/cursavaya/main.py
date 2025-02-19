#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math
import sys
import numpy as np

# Глобальные переменные (DC, ACCURACY) как в C++-коде
DC = 0
ACCURACY = 0


def print_vector_ascii(vec, file_out, title="", formula=""):
    """
    Печатает 1D-вектор в псевдографической таблице,
    добавляя:
      - title (что за вектор)
      - formula (краткое пояснение)
      - сумму элементов.
    """
    n = len(vec)
    
    file_out.write(f"=== {title} ===\n")
    if formula:
        file_out.write(f"Пояснение/формула: {formula}\n")
    
    # Преобразуем все элементы в строки, чтобы найти максимальную ширину
    str_vals = [f"{val:.3f}" for val in vec]
    max_len = max(len(x) for x in str_vals) if str_vals else 5
    
    # Печатаем рамку (верх)
    # +----+----+ ...
    # У нас одна строка, но n столбцов
    def horizontal_border(cols):
        pieces = []
        for _ in range(cols):
            pieces.append("+" + "-"*(max_len+2))
        pieces.append("+\n")
        return "".join(pieces)
    
    file_out.write(horizontal_border(n))
    
    # Теперь сам ряд
    file_out.write("".join(f"| {val:^{max_len}} " for val in str_vals) + "|\n")
    
    # Рамка (низ)
    file_out.write(horizontal_border(n))
    
    # Сумма
    total_sum = sum(vec)
    file_out.write(f"Сумма элементов вектора: {total_sum:.3f}\n\n")


def print_matrix_ascii(matrix, file_out, title="", formula=""):
    """
    Печатает 2D-матрицу в псевдографической таблице,
    добавляя:
      - title (что за матрица)
      - formula (краткое пояснение)
      - сумму элементов матрицы
    """
    n = len(matrix)
    if n == 0:
        file_out.write(f"Матрица «{title}» пуста!\n\n")
        return
    
    file_out.write(f"=== {title} ===\n")
    if formula:
        file_out.write(f"Пояснение/формула: {formula}\n")
    
    # Сформируем строковые представления всех элементов
    str_vals = []
    for i in range(n):
        row_str = []
        for j in range(len(matrix[i])):
            row_str.append(f"{matrix[i][j]:.3f}")
        str_vals.append(row_str)
    
    # Находим макс. длину числа
    max_len = 0
    for row in str_vals:
        for val in row:
            if len(val) > max_len:
                max_len = len(val)
    
    # Функция для печати горизонтальной границы
    def horizontal_border(cols):
        pieces = []
        for _ in range(cols):
            pieces.append("+" + "-"*(max_len+2))
        pieces.append("+\n")
        return "".join(pieces)
    
    # Печать рамки (верх)
    file_out.write(horizontal_border(n))
    
    # Печать строк
    for i in range(n):
        row_to_print = ""
        for j in range(n):
            val_str = str_vals[i][j]
            row_to_print += f"| {val_str:^{max_len}} "
        row_to_print += "|\n"
        file_out.write(row_to_print)
        file_out.write(horizontal_border(n))
    
    # Подсчитываем сумму матрицы
    total_sum = sum(sum(row) for row in matrix)
    file_out.write(f"Сумма всех элементов матрицы: {total_sum:.3f}\n\n")


##############################################################################
#                   Алгоритмические функции 
##############################################################################

def original_Floyd_Warshall(matrixR1, matrixR2):
    """
    Выполняет алгоритм Флойда–Уоршелла и заполняет:
      matrixR1[i][j] = кратчайшая дистанция между i и j
      matrixR2[i][j] = следующий узел на пути i->j (1-индексация)
    matrixR1 и matrixR2 — списки списков (2D).
    """
    n = len(matrixR1)
    # Инициализация matrixR2: iota(matrixR2[i].begin(), matrixR2[i].end(), 1)
    for i in range(n):
        for j in range(n):
            matrixR2[i][j] = j+1  # 1-индексация
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i != j and i != k and j != k:
                    x = matrixR1[i][k] + matrixR1[k][j]
                    y = matrixR1[i][j]
                    if x < y:
                        matrixR1[i][j] = x
                        matrixR2[i][j] = matrixR2[i][k]

def load_intensity(matrixY, matrixR2):
    """
    Аналог функции load_intensity из C++:
    matrixY_hatch[i][j] = суммарная нагрузка на ребро (i->j),
    восстанавливая маршрут через matrixR2.
    
    matrixY - матрица интенсивностей (n x n).
    matrixR2 - матрица маршрутов (n x n), хранящая "следующий узел" (1..n).
    """
    n = len(matrixY)
    matrixY_hatch = [[0.0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            flow_ij = matrixY[i][j]
            if flow_ij == 0 or i == j:
                continue
            # Первый сегмент пути
            next_ij = matrixR2[i][j] - 1
            matrixY_hatch[i][next_ij] += flow_ij
            k = next_ij
            # Проходим, пока не дойдем до j
            while k != j:
                nxt = matrixR2[k][j] - 1
                matrixY_hatch[k][nxt] += flow_ij
                k = nxt
    return matrixY_hatch

def gen_streams_matrix(matrixY_hatch, quality):
    """
    Аналог gen_streams_matrix из C++.
    matrixY_hatch - n x n, нагрузки на ребрах (float).
    quality - требуемое качество (например, 0.98).
    
    Возвращаем matrixV (число каналов).
    """
    n = len(matrixY_hatch)
    p_max = 1.0 - quality  # допустимая вероятность блокировки
    matrixV = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            y = matrixY_hatch[i][j]
            if y == 0:
                matrixV[i][j] = 0
            else:
                v = 1
                p = 1.0
                numerator = y
                summ = y
                # пока p > p_max => наращиваем v
                while p > p_max:
                    v += 1
                    numerator = (numerator / v) * y
                    summ += numerator
                    p = numerator / summ
                matrixV[i][j] = v
    return matrixV

def calc_delays(Rij, Aij, Bij, Tij, L):
    """
    Аналог calc_delays из C++.
    M/M/1: T_ij = (8*L) / (B_ij - A_ij), если есть прямая связь i->j,
    иначе 0, и суммируем по всем промежуточным узлам.
    
    Rij[i][j] = след. узел (1..n),
    Aij[i][j] = A (число, пропускная способность?), 
    Bij[i][j] = B (пропускная способность),
    Tij[i][j] = матрица задержек (заполняем).
    L (байты) => 8*L (биты).
    """
    n = len(Tij)
    # Сначала прямые задержки
    for i in range(n):
        for j in range(n):
            if i == j:
                Tij[i][j] = 0.0
            else:
                # прямая ли связь?
                if Rij[i][j] == (j+1):  # если R2[i][j] == j+1
                    if Bij[i][j] > Aij[i][j] and Aij[i][j] != 0:
                        Tij[i][j] = (8.0 * L) / (Bij[i][j] - Aij[i][j])
                    else:
                        Tij[i][j] = 0.0
                else:
                    Tij[i][j] = 0.0
    # Затем учитываем цепочки
    for i in range(n):
        for j in range(n):
            if i != j:
                if Rij[i][j] != (j+1):
                    # составной маршрут
                    total = Tij[i][Rij[i][j]-1]
                    k = Rij[i][j]-1
                    while k != j:
                        nxt = Rij[k][j] - 1
                        total += Tij[k][nxt]
                        k = nxt
                    Tij[i][j] = total

def calc_O(Tij, T0):
    """
    Аналог calc_O в C++:
    O = sum((t - T0/2)^2) по всем t в Tij.
    """
    O_val = 0.0
    for row in Tij:
        for t in row:
            diff = (t - (T0/2))
            O_val += diff*diff
    return O_val

def optimize_BMatrix_sub(Rij, Aij, Bij, T0, L):
    """
    Подобно optimize_BMatrix_sub из C++:
    - Перебираем все (i,j), где Bij[i][j] != 0
    - Пробуем увеличить Bij[i][j] на DC, считаем задержки => O
    - Находим минимум O => bestI,bestJ
    - Фиксируем увеличение Bij[bestI][bestJ] на DC
    - Повторяем, пока улучшения есть
    """
    n = len(Bij)
    Tij = [[0.0]*n for _ in range(n)]
    INF = 1e20
    bestO = INF
    while True:
        changed = False
        bestI = 0
        bestJ = 0
        for i in range(n):
            for j in range(n):
                if Bij[i][j] != 0:
                    Bij[i][j] += DC
                    calc_delays(Rij, Aij, Bij, Tij, L)
                    Bij[i][j] -= DC
                    O = calc_O(Tij, T0)
                    if O < bestO:
                        bestO = O
                        bestI = i
                        bestJ = j
                        changed = True
        if changed:
            Bij[bestI][bestJ] += DC
        else:
            break
    calc_delays(Rij, Aij, Bij, Tij, L)
    return Tij

def check_optimize(Tij, T0):
    """
    Аналог check_optimize из C++:
    проверяем, нет ли x > T0/2 в Tij.
    Если все <= T0/2, возвращаем True.
    """
    n = len(Tij)
    halfT0 = T0/2
    for row in Tij:
        for x in row:
            if x > halfT0:
                return False
    return True

def optimize_BMatrix(Rij, Aij, Bij, T0, L, is_optimizeT0):
    """
    Полный аналог optimize_BMatrix.
    """
    global DC, ACCURACY
    old_T0 = T0
    dT = T0 / ACCURACY if ACCURACY != 0 else 0.0000001
    
    Tij = optimize_BMatrix_sub(Rij, Aij, Bij, T0, L)
    while is_optimizeT0 and (not check_optimize(Tij, old_T0)) and (T0 - dT > 1e-20):
        T0 -= dT
        Tij = optimize_BMatrix_sub(Rij, Aij, Bij, T0, L)
    return (T0, Tij)

##############################################################################
#                                  MAIN
##############################################################################

def main():
    # Считываем input_file.txt
    with open("input_file.txt", "r", encoding="utf-8") as f:
        lines = []
        for line in f:
            # отбрасываем комментарии ';'
            if ';' in line:
                line = line[:line.index(';')]
            line = line.strip()
            if line:
                lines.append(line)
    # Объединим всё в одну строку, потом разобьём
    content = " ".join(lines)
    parts = content.split()
    idx = 0
    
    # 1) Считываем основные параметры
    n = int(parts[idx]); idx+=1
    y0 = float(parts[idx]); idx+=1
    a0 = float(parts[idx]); idx+=1
    L = float(parts[idx]); idx+=1   # длина пакета (байты)
    quality = float(parts[idx]); idx+=1  # например, 0.98
    T0 = float(parts[idx]); idx+=1
    optimizeT0_flag = int(parts[idx]); idx+=1
    global DC, ACCURACY
    DC = int(parts[idx]); idx+=1
    ACCURACY = int(parts[idx]); idx+=1
    
    # 2) Количество абонентов (n штук)
    subscribers = [float(parts[idx+i]) for i in range(n)]
    idx += n
    
    # 3) Матрица расстояний (n x n)
    distance_matrix = []
    for i in range(n):
        row_i = []
        for j in range(n):
            val = parts[idx]
            idx += 1
            # Если "90000000000" => math.inf
            if val.lower() == "inf" or val == "90000000000":
                row_i.append(math.inf)
            else:
                row_i.append(float(val))
        distance_matrix.append(row_i)
    
    # Теперь начинаем расчёт
    f_out = open("output_file.txt","w",encoding="utf-8")
    
    # 1) Интенсивности в узлах: Y_i = subscribers[i] * y0
    matrixY = [s * y0 for s in subscribers]
    print_vector_ascii(
        matrixY, 
        f_out, 
        title="Интенсивности производимого в узлах сети трафика (Y_i)", 
        formula="Y_i = subscribers[i]*y0"
    )
    
    # 2) Коэффициенты распределения (k_i = Y_i / sum(Y))
    sumY = sum(matrixY)
    matrixK = [y / sumY for y in matrixY]
    print_vector_ascii(
        matrixK,
        f_out,
        title="Коэффициенты распределения трафика (k_i)",
        formula="k_i = Y_i / Σ(Y_j)"
    )
    
    # 3) Матрица интенсивностей Yij[i][j] = Y[i] * k[j]
    Yij = [[0.0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            Yij[i][j] = matrixY[i] * matrixK[j]
    print_matrix_ascii(
        Yij,
        f_out,
        title="Матрица интенсивностей трафика (Yij)",
        formula="Yij[i][j] = Y_i * k_j"
    )
    
    # 4) Флойд–Уоршелл
    matrixR1 = [row[:] for row in distance_matrix]  # копия
    matrixR2 = [[0]*n for _ in range(n)]
    original_Floyd_Warshall(matrixR1, matrixR2)
    print_matrix_ascii(
        matrixR1,
        f_out,
        title="Матрица кратчайших расстояний (R1)",
        formula="Алгоритм Флойда–Уоршелла"
    )
    print_matrix_ascii(
        matrixR2,
        f_out,
        title="Матрица кратчайших маршрутов (R2)",
        formula="Следующий узел на пути i->j"
    )
    
    # 5) Матрица интенсивностей нагрузок (Y_hatch)
    Y_hatch = load_intensity(Yij, matrixR2)
    print_matrix_ascii(
        Y_hatch,
        f_out,
        title="Матрица интенсивностей нагрузок (Y_hatch)",
        formula="Суммарная нагрузка на каждом ребре, исходя из маршрутов"
    )
    
    # 6) Матрица потоков (число каналов)
    streams_matrix = gen_streams_matrix(Y_hatch, quality)
    print_matrix_ascii(
        streams_matrix,
        f_out,
        title="Матрица потоков (число каналов) (V)",
        formula="Число каналов при допустимой вероятности блокировки = 1 - quality"
    )
    
    # 7) Матрица интенсивности трафика ПД: Aij = streams_matrix * a0
    Aij = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            Aij[i][j] = streams_matrix[i][j] * a0
    print_matrix_ascii(
        Aij,
        f_out,
        title="Матрица интенсивности трафика ПД (Aij)",
        formula="Aij[i][j] = V[i][j] * a0"
    )
    
    # 8) Матрица пропускных способностей Bij
    # Bij[i][j] = (Aij[i][j] != 0)? Aij[i][j] + (8*L)/T0 : 0
    Bij = [[0.0]*n for _ in range(n)]
    add_term = 8.0*L / T0
    for i in range(n):
        for j in range(n):
            if Aij[i][j] != 0:
                Bij[i][j] = Aij[i][j] + add_term
            else:
                Bij[i][j] = 0.0
    print_matrix_ascii(
        Bij,
        f_out,
        title="Матрица пропускных способностей (Bij)",
        formula="Bij[i][j] = Aij[i][j] + (8*L)/T0, если Aij!=0 иначе 0"
    )
    
    # 9) и 10) Оптимизация
    is_optimize = (optimizeT0_flag != 0)
    T0_new, Tij = optimize_BMatrix(matrixR2, Aij, Bij, T0, L, is_optimize)
    
    print_matrix_ascii(
        Tij,
        f_out,
        title="Матрица задержек (Tij)",
        formula="M/M/1: T_ij = (8*L)/(B_ij - A_ij), сумм. по узлам маршрута"
    )
    print_matrix_ascii(
        Bij,
        f_out,
        title="Матрица оптимизированных пропускных способностей (Bij)",
        formula="После итераций optimize_BMatrix"
    )
    
    f_out.write(f"Оптимизированное T: {T0_new}\n")
    
    f_out.close()
    print("Done. Данные записаны в 'output_file.txt'.")

if __name__ == "__main__":
    main()
