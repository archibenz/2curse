#!/bin/bash

# Компиляция C++ программ
g++ -o lab1 lab1.cpp
g++ -o lab1_1 lab1_1.cpp
g++ -o lab1_2 lab1_2.cpp

# Запуск скомпилированных программ
./lab1
./lab1_1
./lab1_2

# Запуск Python-скриптов параллельно
python3 lab1-plot.py &
python3 lab1_1-plot.py &
python3 lab1_2-plot.py &
wait  # Ждём завершения всех процессов