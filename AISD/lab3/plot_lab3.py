import os
import numpy as np
import matplotlib.pyplot as plt
import sys
import time
from datetime import datetime
import matplotlib  # Import matplotlib directly for version checking
import argparse

def read_csv_history(filename):
    """Чтение истории из CSV файла"""
    if not os.path.exists(filename):
        print(f"Файл {filename} не существует")
        return np.array([])
    
    # Получаем размер и время изменения файла
    file_size = os.path.getsize(filename)
    mod_time = datetime.fromtimestamp(os.path.getmtime(filename)).strftime('%Y-%m-%d %H:%M:%S')
    print(f"Файл {filename}: размер {file_size} байт, изменен {mod_time}")
    
    try:
        # Принудительно перечитываем файл
        with open(filename, 'r') as f:
            content = f.readlines()
        
        print(f"Прочитано {len(content)} строк из {filename}")
        
        if len(content) <= 1:  # Файл пуст или содержит только заголовок
            print(f"Файл {filename} пуст или содержит только заголовок")
            return np.array([])
            
        # Пропускаем заголовок
        data = [float(line.strip()) for line in content[1:] if line.strip()]
        print(f"Получено {len(data)} значений: первое={data[0] if data else 'нет'}, последнее={data[-1] if data else 'нет'}")
        return np.array(data)
    except Exception as e:
        print(f"Ошибка при чтении {filename}: {e}")
        return np.array([])

def f(x):
    """Целевая функция"""
    return x**2 + 4*np.sin(x)

def main(timestamp=None):
    # Если временная метка не передана, создаем её
    if timestamp is None:
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
    
    print(f"Запуск визуализации с временной меткой: {timestamp}")
    
    # Принудительно отключаем интерактивный режим для избежания кэширования
    plt.ioff()
    
    # Настройки для графиков
    plt.rcParams.update({'font.size': 12})
    
    # Информация о текущем состоянии
    print(f"Python: {sys.version}")
    print(f"NumPy: {np.__version__}")
    print(f"Matplotlib: {matplotlib.__version__}")
    print(f"Текущий каталог: {os.getcwd()}")
    print(f"Запущен в: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    
    # Информация о доступных файлах
    print("\nДоступные файлы для обработки:")
    csv_files = [f for f in os.listdir('.') if f.endswith('.csv')]
    txt_files = [f for f in os.listdir('.') if f.endswith('.txt')]
    print(f"CSV файлы: {csv_files if csv_files else 'нет'}")
    print(f"TXT файлы: {txt_files if txt_files else 'нет'}")
    
    # Кратковременная задержка для гарантированного завершения записи файлов
    time.sleep(0.5)
    
    # Чтение историй из CSV-файлов с приоритетом над TXT
    dicho_history = read_csv_history('dichotomy_hist.csv')
    if len(dicho_history) == 0:
        dicho_history = read_csv_history('dichotomy_hist.txt')
        if len(dicho_history) > 0:
            print("Использую данные из TXT файла для дихотомии")
    
    golden_history = read_csv_history('golden_hist.csv')
    if len(golden_history) == 0:
        golden_history = read_csv_history('golden_hist.txt')
        if len(golden_history) > 0:
            print("Использую данные из TXT файла для золотого сечения")
    
    fib_history = read_csv_history('fibonacci_hist.csv')
    if len(fib_history) == 0:
        fib_history = read_csv_history('fibonacci_hist.txt')
        if len(fib_history) > 0:
            print("Использую данные из TXT файла для Фибоначчи")
    
    brute_history = read_csv_history('brute_hist.csv')
    
    # Проверяем, что у нас есть данные хотя бы для одного метода
    methods_data = []
    method_names = []
    
    if len(dicho_history) > 0:
        methods_data.append((dicho_history, 'red', 'o', 'Дихотомия'))
        method_names.append('Дихотомия')
    
    if len(golden_history) > 0:
        methods_data.append((golden_history, 'green', 's', 'Золотое сечение'))
        method_names.append('Золотое сечение')
    
    if len(fib_history) > 0:
        methods_data.append((fib_history, 'blue', '^', 'Фибоначчи'))
        method_names.append('Фибоначчи')
    
    if len(methods_data) == 0:
        print("Ошибка: не удалось прочитать данные ни для одного метода.")
        return
    
    try:
        # Создаем фигуру с четырьмя графиками
        fig, axs = plt.subplots(2, 2, figsize=(18, 12))
        
        # собираем все истории и названия методов
        histories = [dicho_history, golden_history, fib_history]
        method_names = ['Дихотомия', 'Золотое сечение', 'Фибоначчи']
        if len(brute_history) > 0:
            histories.append(brute_history)
            method_names.append('Brute Force')

        # 1. График сходимости (semilogy)
        axs[0, 0].clear()
        for hist, name in zip(histories, method_names):
            iters = np.arange(1, len(hist) + 1)
            errors = np.abs(hist - hist[-1])
            axs[0, 0].semilogy(iters, errors, label=name)
        axs[0, 0].set_xlabel('Итерация')
        axs[0, 0].set_ylabel('|xₖ - x*|')
        axs[0, 0].set_title('Сходимость методов')
        axs[0, 0].legend()
        axs[0, 0].grid(True)

        # 2. График f(x) и точки
        axs[0, 1].clear()
        # динамический диапазон по данным
        x_min_val = min(h[0] for h in histories if len(h)>0)
        x_max_val = max(h[-1] for h in histories if len(h)>0)
        x = np.linspace(x_min_val, x_max_val, 500)
        axs[0, 1].plot(x, f(x), 'k-', label='f(x)')
        for hist, name in zip(histories, method_names):
            if len(hist)>0:
                axs[0, 1].scatter([hist[0]], [f(hist[0])], marker='o', label=f'{name} start')
                axs[0, 1].scatter([hist[-1]], [f(hist[-1])], marker='*', label=f'{name} end')
        axs[0, 1].set_xlabel('x')
        axs[0, 1].set_ylabel('f(x)')
        axs[0, 1].set_title('Целевая функция и точки')
        axs[0, 1].legend()
        axs[0, 1].grid(True)

        # 3. Bar chart – число итераций
        axs[1, 0].clear()
        counts = [len(h) for h in histories]
        axs[1, 0].bar(method_names, counts)
        axs[1, 0].set_xlabel('Метод')
        axs[1, 0].set_ylabel('Число итераций')
        axs[1, 0].set_title('Итерации до сходимости')

        # 4. Bar chart – ускорение (speedup)
        axs[1, 1].clear()
        base = len(brute_history) if len(brute_history)>0 else max(counts)
        speedups = [base/len(h) if len(h)>0 else 1 for h in histories]
        axs[1, 1].bar(method_names, speedups)
        axs[1, 1].set_xlabel('Метод')
        axs[1, 1].set_ylabel('Ускорение (раз)')
        axs[1, 1].set_title('Speedup относительно Brute Force')

        # финальная отрисовка
        plt.tight_layout()
        plt.savefig(f'optimization_comparison_{timestamp}.png', dpi=300)
        plt.savefig('optimization_comparison.png', dpi=300)
        plt.show()

    except Exception as e:
        import traceback
        print(f"Ошибка при создании графика: {e}")
        traceback.print_exc()

if __name__ == "__main__":
    # Обработка аргументов командной строки
    parser = argparse.ArgumentParser(description='Построение графиков для методов оптимизации')
    parser.add_argument('--timestamp', help='Временная метка для имени файла')
    args = parser.parse_args()
    main(timestamp=args.timestamp)