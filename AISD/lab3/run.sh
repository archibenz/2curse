#!/usr/bin/env bash
set -e
g++ -std=c++17 -O2 main.cpp -o lab
echo "[*] Запускаем C++‑часть"
./lab
echo "[*] Строим графики Python’ом"
python3 plot.py