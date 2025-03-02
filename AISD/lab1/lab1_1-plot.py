import matplotlib.pyplot as plt
import numpy as np

# Читаем отсортированные данные
data = []
with open("quick_sorted_data.txt", "r") as file:
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
with open("quick_execution_time.txt", "r") as file:
    for line in file:
        parts = line.strip().split()
        if len(parts) >= 2:  # Ensure we have both size and time
            sizes.append(int(parts[0]))
            execution_times.append(float(parts[1]))

# Use the execution time for the largest array size
execution_time = execution_times[-1] if execution_times else 0

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