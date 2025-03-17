#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Project directory
PROJECT_DIR="$(dirname "$0")"
cd "$PROJECT_DIR"

echo -e "${BLUE}=== Факториальный анализ: Настройка и выполнение ===${NC}"

# Step 1: Set up Python virtual environment
echo -e "${BLUE}[1/5] Настройка виртуального окружения Python...${NC}"
VENV_DIR="venv"

if [ ! -d "$VENV_DIR" ]; then
    echo "Создание нового виртуального окружения..."
    python3 -m venv "$VENV_DIR" || { echo -e "${RED}Ошибка при создании виртуального окружения!${NC}"; exit 1; }
else
    echo "Виртуальное окружение уже существует."
fi

# Activate virtual environment
echo "Активация виртуального окружения..."
source "$VENV_DIR/bin/activate" || { echo -e "${RED}Ошибка при активации виртуального окружения!${NC}"; exit 1; }

# Step 2: Install required Python packages
echo -e "${BLUE}[2/5] Установка необходимых Python-пакетов...${NC}"
pip install matplotlib pandas numpy || { echo -e "${RED}Ошибка при установке Python-пакетов!${NC}"; exit 1; }

# Step 3: Compile the C++ program
echo -e "${BLUE}[3/5] Компиляция C++ программы...${NC}"
g++ -std=c++17 -o factorial_program lab3.cpp || { echo -e "${RED}Ошибка компиляции C++ программы!${NC}"; exit 1; }
echo -e "${GREEN}Компиляция успешно завершена.${NC}"

# Step 4: Generate timing data using the new feature in the C++ program
echo -e "${BLUE}[4/5] Генерация данных о времени выполнения...${NC}"

# Run the program with option 5 (generate data for graph)
echo "Генерация данных для значений от 1 до 20..."
# Create input for the program: option 5 (generate data), 20 for max_n, then 6 to exit
echo -e "5\n20\n6" | ./factorial_program || { echo -e "${RED}Ошибка при запуске программы для генерации данных!${NC}"; exit 1; }

echo -e "Данные сохранены в файл factorial_times.txt"

# Step 5: Run the Python visualization script
echo -e "${BLUE}[5/5] Запуск визуализации в Python...${NC}"
python factorial_performance_plot.py || { echo -e "${RED}Ошибка при запуске Python-скрипта!${NC}"; exit 1; }

# Deactivate virtual environment
deactivate

echo -e "${GREEN}=== Анализ успешно завершен! ===${NC}"
echo "График сохранен в factorial_comparison.png"

exit 0