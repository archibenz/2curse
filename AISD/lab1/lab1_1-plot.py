import matplotlib.pyplot as plt
import numpy as np

# Читаем отсортированные данные
with open("quick_sorted_data.txt", "r") as file:
    data = [int(line.strip()) for line in file]

# Читаем время выполнения сортировки
with open("quick_execution_time.txt", "r") as file:
    execution_time = float(file.readline().strip())

# Генерация количества элементов для графика
n = len(data)
complexity = [i * np.log2(i + 1) for i in range(1, n + 1)]  # O(n log n)

# Построение графика сложности и времени выполнения
plt.figure(figsize=(10, 5))

# График сложности O(n log n)
plt.plot(range(1, n + 1), complexity, label="O(n log n) complexity", color="red")

# Отображение фактического времени выполнения сортировки
plt.axhline(y=execution_time, color="blue", linestyle="--", label=f"Execution Time: {execution_time:.6f} sec")

plt.xlabel("Размер массива")
plt.ylabel("Количество операций / Время выполнения (сек)")
plt.title("Оценка сложности быстрой сортировки (Хоара)")
plt.legend()
plt.grid()
plt.show()