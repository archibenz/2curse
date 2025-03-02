#!/bin/bash

# Компиляция C++ программ
GCC_COMPILER=/opt/homebrew/bin/g++-14

$GCC_COMPILER -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp -o lab1 lab1.cpp
$GCC_COMPILER -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp -o lab1_1 lab1_1.cpp
$GCC_COMPILER -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp -o lab1_2 lab1_2.cpp

# ✅ Запуск программ (чтобы создать файлы)
./lab1
./lab1_1
./lab1_2

# ✅ Проверка наличия файлов перед запуском Python-скриптов
if [[ ! -f "sorted_data.txt" || ! -f "quick_sorted_data.txt" || ! -f "selection_sorted_data.txt" ]]; then
    echo "❌ Ошибка: Не все файлы результатов созданы!"
    exit 1
fi

# ✅ Запуск Python-скриптов
python3 lab1-plot.py &
python3 lab1_1-plot.py &
python3 lab1_2-plot.py &
wait

echo "✅ Скрипт выполнен успешно!"