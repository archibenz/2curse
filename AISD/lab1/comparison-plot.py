
import matplotlib.pyplot as plt
import numpy as np

# Function to read time data from a file
def read_execution_times(filename):
    sizes = []
    times = []
    with open(filename, "r") as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) >= 2:
                sizes.append(int(parts[0]))
                times.append(float(parts[1]))
    return sizes, times

# Read execution times for all three sorting algorithms
insertion_sizes, insertion_times = read_execution_times("execution_time.txt")
quick_sizes, quick_times = read_execution_times("quick_execution_time.txt")
selection_sizes, selection_times = read_execution_times("selection_execution_time.txt")

# Create the comparison plot
plt.figure(figsize=(12, 8))

# Plot each sorting algorithm with different colors and markers
plt.plot(insertion_sizes, insertion_times, 'ro-', label='Insertion Sort', linewidth=2)
plt.plot(quick_sizes, quick_times, 'bs-', label='Quick Sort', linewidth=2)
plt.plot(selection_sizes, selection_times, 'gD-', label='Selection Sort', linewidth=2)

# Add labels and title
plt.xlabel('Размер массива', fontsize=14)
plt.ylabel('Время выполнения (сек)', fontsize=14)
plt.title('Сравнение времени выполнения алгоритмов сортировки', fontsize=16)

# Add grid for better readability
plt.grid(True, linestyle='--', alpha=0.7)

# Add legend
plt.legend(fontsize=12)

# Optional: Annotate theoretical complexities
plt.annotate('O(n²)', xy=(insertion_sizes[-1], insertion_times[-1]), 
             xytext=(insertion_sizes[-1]+50, insertion_times[-1]*1.1),
             arrowprops=dict(facecolor='black', shrink=0.05, width=1.5))

plt.annotate('O(n log n)', xy=(quick_sizes[-1], quick_times[-1]),
             xytext=(quick_sizes[-1]+50, quick_times[-1]*1.1),
             arrowprops=dict(facecolor='black', shrink=0.05, width=1.5))

# Save the plot
plt.savefig('sorting_comparison.png', dpi=300, bbox_inches='tight')

# Show the plot
plt.show()

# Additional visualization: Logarithmic scale for better comparison of growth rates
plt.figure(figsize=(12, 8))
plt.loglog(insertion_sizes, insertion_times, 'ro-', label='Insertion Sort', linewidth=2)
plt.loglog(quick_sizes, quick_times, 'bs-', label='Quick Sort', linewidth=2) 
plt.loglog(selection_sizes, selection_times, 'gD-', label='Selection Sort', linewidth=2)

# Add labels and title
plt.xlabel('Размер массива (log scale)', fontsize=14)
plt.ylabel('Время выполнения (сек, log scale)', fontsize=14)
plt.title('Сравнение времени выполнения алгоритмов сортировки (логарифмическая шкала)', fontsize=16)

plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=12)

# Save the logarithmic plot
plt.savefig('sorting_comparison_log_scale.png', dpi=300, bbox_inches='tight')

# Show the plot
plt.show()