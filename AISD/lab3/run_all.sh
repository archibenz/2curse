#!/bin/bash

# Очистка старых данных и принудительное удаление всех кэшей
echo "=== Очистка предыдущих результатов ==="
rm -f *.csv *.txt *.png
find . -name "__pycache__" -type d -exec rm -rf {} +  2>/dev/null || true
find . -name "*.pyc" -delete
echo "Файлы очищены: $(ls -la)"

# Явно меняем текущий каталог для гарантии правильности путей
cd "$(dirname "$0")"
CURRENT_DIR="$(pwd)"
echo "Текущий каталог: $CURRENT_DIR"

# Компиляция и запуск основной программы
echo -e "\n=== Компиляция и запуск основной программы ==="
g++ -std=c++17 -O2 -o lab3 lab3.cpp
if [ $? -eq 0 ]; then
    ./lab3 "$@"
    
    # Проверяем, что файлы созданы
    echo "Созданы файлы для визуализации:"
    ls -lh *_hist.txt 2>/dev/null || echo "Предупреждение: Файлы .txt не созданы!"
    
    # Проверяем, что в файлах есть данные
    for file in *_hist.txt; do
        if [ -f "$file" ]; then
            echo "Содержимое $file (первые 5 строк):"
            head -n 5 "$file"
        fi
    done
else
    echo "Compilation of lab3.cpp failed"
    exit 1
fi

# Компиляция и запуск бенчмарка как отдельного проекта
echo -e "\n=== Компиляция и запуск бенчмарка ==="
g++ -std=c++17 -O2 -o lab3_benchmark lab3_benchmark.cpp 
if [ $? -eq 0 ]; then
    ./lab3_benchmark
    
    # Проверяем, что CSV файлы созданы
    echo "Созданы файлы для визуализации:"
    ls -lh *_hist.csv 2>/dev/null || echo "Предупреждение: Файлы .csv не созданы!"
    
    # Проверяем содержимое CSV файлов
    for file in *_hist.csv; do
        if [ -f "$file" ]; then
            echo "Содержимое $file (первые 5 строк):"
            head -n 5 "$file"
        fi
    done
else
    echo "Compilation of lab3_benchmark.cpp failed"
    exit 1
fi

# --- Python virtual environment setup ---
echo -e "\n=== Настройка и запуск визуализации ==="
if [ ! -d ".venv" ]; then
    python3 -m venv .venv
fi
source .venv/bin/activate

# Установка зависимостей с явным выводом
echo "Установка зависимостей Python..."
pip install --upgrade pip
pip install matplotlib numpy

# Добавляем временную метку к имени файла графика для предотвращения кэширования
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
echo "Запуск визуализации с временной меткой: $TIMESTAMP"

# Запускаем скрипт напрямую с параметром timestamp
echo "Запуск plot_lab3.py..."
python plot_lab3.py --timestamp $TIMESTAMP

# Проверяем, что графики созданы
if [ -f "optimization_comparison.png" ]; then
    echo "Графики успешно созданы."
else
    echo "ОШИБКА: Графики не были созданы!"
fi

deactivate

echo -e "\n=== Готово! Сравнительные графики сохранены в PNG файлы ==="
# Вывод только последних созданных файлов
ls -la *.png 2>/dev/null || echo "Внимание: PNG файлы не найдены!"