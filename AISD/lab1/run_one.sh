
#!/bin/bash

echo "🚀 Starting compilation and execution of sorting algorithms..."

# Компиляция C++ программ
GCC_COMPILER=/opt/homebrew/bin/g++-14

echo "📊 Compiling insertion sort..."
$GCC_COMPILER -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp -o lab1 lab1.cpp

echo "📊 Compiling quick sort..."
$GCC_COMPILER -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp -o lab1_1 lab1_1.cpp

echo "📊 Compiling selection sort..."
$GCC_COMPILER -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp -o lab1_2 lab1_2.cpp

echo "🧪 Running sorting algorithms to generate data..."
./lab1
./lab1_1
./lab1_2

# Проверка наличия файлов перед запуском Python-скрипта
if [[ ! -f "sorted_data.txt" || ! -f "quick_sorted_data.txt" || ! -f "selection_sorted_data.txt" ]]; then
    echo "❌ Ошибка: Не все файлы результатов созданы!"
    exit 1
fi

if [[ ! -f "execution_time.txt" || ! -f "quick_execution_time.txt" || ! -f "selection_execution_time.txt" ]]; then
    echo "❌ Ошибка: Не все файлы с временем выполнения созданы!"
    exit 1
fi

echo "📈 Generating comparison plot..."
python3 comparison-plot.py

echo "✅ Все алгоритмы выполнены и визуализированы на одном графике!"
echo "📊 Результаты сохранены в файлах sorting_comparison.png и sorting_comparison_log_scale.png"