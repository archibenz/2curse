import matplotlib.pyplot as plt
import numpy as np

# Читаем отсортированные данные
data = []
with open("selection_sorted_data.txt", "r") as file:
    for line in file:
        line = line.strip()
        # Skip header lines and empty lines
        if not line or line.startswith("#"):
            continue
        # Parse the numbers from this line
        data.extend([int(x) for x in line.split()])

# Читаем время выполнения сортировки
sizes = []
execution_times = []
with open("selection_execution_time.txt", "r") as file:
    for line in file:
        parts = line.strip().split()
        if len(parts) >= 2:  # Ensure we have both size and time
            sizes.append(int(parts[0]))
            execution_times.append(float(parts[1]))

# Use the execution time for the largest array size
execution_time = execution_times[-1] if execution_times else 0

# Генерация количества элементов для графика
n = len(data)

# Оценка сложности O(n^2)
complexity = [i**2 for i in range(1, n + 1)]

# Построение графика
plt.figure(figsize=(10, 5))

# График сложности O(n^2)
plt.plot(range(1, n + 1), complexity, label="O(n^2) complexity", color="red")

# Линия, отображающая фактическое время выполнения
plt.axhline(y=execution_time, color="blue", linestyle="--",
            label=f"Execution Time: {execution_time:.6f} sec")

plt.xlabel("Размер массива")
plt.ylabel("Количество операций / Время выполнения (сек)")
plt.title("Оценка сложности сортировки выбором")
plt.legend()
plt.grid()
plt.show()

