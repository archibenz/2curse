try:
    import pandas as pd
except ImportError:
    print("Pandas не установлен. Пробуем использовать базовые библиотеки...")
    pd = None

import matplotlib.pyplot as plt
import numpy as np
import csv
import os
from matplotlib.ticker import ScalarFormatter

# Set font for plots
plt.rcParams['font.family'] = 'DejaVu Sans'

try:
    # Read data files
    if pd is not None:
        binary_data = pd.read_csv('binary_search_results.txt')
        bst_data = pd.read_csv('bst_search_results.txt')
        hash_data = pd.read_csv('hash_search_results.txt')
        
        # Convert nanoseconds to seconds
        binary_data['Time(s)'] = binary_data['Time(ns)'] / 1e9
        bst_data['Time(s)'] = bst_data['Time(ns)'] / 1e9
        hash_data['Time(s)'] = hash_data['Time(ns)'] / 1e9
    else:
        # Manual CSV reading if pandas is not available
        binary_data = {'Size': [], 'Time(s)': []}
        bst_data = {'Size': [], 'Time(s)': []}
        hash_data = {'Size': [], 'Time(s)': []}
        
        # Read binary search data
        with open('binary_search_results.txt', 'r') as f:
            reader = csv.reader(f)
            next(reader)  # skip header
            for row in reader:
                binary_data['Size'].append(int(row[0]))
                binary_data['Time(s)'].append(float(row[1]) / 1e9)
        
        # Read BST search data
        with open('bst_search_results.txt', 'r') as f:
            reader = csv.reader(f)
            next(reader)  # skip header
            for row in reader:
                bst_data['Size'].append(int(row[0]))
                bst_data['Time(s)'].append(float(row[1]) / 1e9)
        
        # Read hash search data
        with open('hash_search_results.txt', 'r') as f:
            reader = csv.reader(f)
            next(reader)  # skip header
            for row in reader:
                hash_data['Size'].append(int(row[0]))
                hash_data['Time(s)'].append(float(row[1]) / 1e9)
    
    # Create figure for comparison chart
    plt.figure(figsize=(12, 8))
    
    # Use scientific notation for very small numbers
    plt.ticklabel_format(axis='y', style='scientific', scilimits=(0,0))
    
    # Plot data in seconds
    plt.plot(binary_data['Size'], binary_data['Time(s)'], marker='o', linewidth=2, label='Binary Search')
    plt.plot(bst_data['Size'], bst_data['Time(s)'], marker='s', linewidth=2, label='BST Search')
    plt.plot(hash_data['Size'], hash_data['Time(s)'], marker='^', linewidth=2, label='Hash Search')
    
    # Use log scale for x-axis
    plt.xscale('log', base=2)
    
    # Format x-axis to show actual numbers
    plt.gca().xaxis.set_major_formatter(ScalarFormatter())
    plt.xticks(binary_data['Size'], rotation=45)
    
    # Add grid
    plt.grid(True, which="both", ls="-", alpha=0.2)
    
    # Add labels and title
    plt.xlabel('Количество элементов', fontsize=14)
    plt.ylabel('Время поиска (секунды)', fontsize=14)
    plt.title('Сравнение алгоритмов поиска', fontsize=16)
    
    # Add legend
    plt.legend(fontsize=12)
    
    # Adjust layout
    plt.tight_layout()
    
    # Save chart as PNG
    plt.savefig('search_comparison.png', dpi=300, bbox_inches='tight')
    
    # Create a table for comparison
    fig, ax = plt.subplots(figsize=(12, 6))
    ax.axis('tight')
    ax.axis('off')
    
    # Prepare table data with times in seconds (scientific notation)
    table_data = []
    for i, size in enumerate(binary_data['Size']):
        bin_time = binary_data['Time(s)'][i] if isinstance(binary_data['Time(s)'], list) else binary_data['Time(s)'].iloc[i]
        bst_time = bst_data['Time(s)'][i] if isinstance(bst_data['Time(s)'], list) else bst_data['Time(s)'].iloc[i]
        hash_time = hash_data['Time(s)'][i] if isinstance(hash_data['Time(s)'], list) else hash_data['Time(s)'].iloc[i]
        
        # Format times in scientific notation
        bin_time_fmt = "{:.2e}".format(bin_time)
        bst_time_fmt = "{:.2e}".format(bst_time)
        hash_time_fmt = "{:.2e}".format(hash_time)
        
        table_data.append([size, bin_time_fmt, bst_time_fmt, hash_time_fmt])
    
    # Create the table
    table = ax.table(cellText=table_data,
                    colLabels=['Размер массива', 'Бинарный поиск (с)', 'BST поиск (с)', 'Хеш поиск (с)'],
                    loc='center',
                    cellLoc='center')
    
    # Style the table
    table.auto_set_font_size(False)
    table.set_fontsize(10)
    table.scale(1.2, 1.5)
    
    plt.title('Таблица сравнения времени выполнения', fontsize=16)
    plt.tight_layout()
    
    # Save table as PNG
    plt.savefig('search_comparison_table.png', dpi=300, bbox_inches='tight')
    
    print("Графики сравнения успешно созданы:")
    print("1. search_comparison.png - График зависимости времени от размера")
    print("2. search_comparison_table.png - Таблица с результатами")

except Exception as e:
    print(f"Ошибка при создании графика: {e}")
    print("Убедитесь, что C++ программы были запущены для генерации данных.")
