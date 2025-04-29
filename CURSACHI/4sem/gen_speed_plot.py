#!/usr/bin/env python3
"""
Строит график «кол-во потоков — время» из CSV,
который создаёт our::test_generation_time_by_thread_num().
"""
import sys, csv, matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

if len(sys.argv) != 3:
    sys.exit("usage: gen_speed_plot.py <csv> <png>")

csv_file, out_png = sys.argv[1], sys.argv[2]
from collections import defaultdict, OrderedDict

# собираем времена в список для каждого числа потоков
acc = defaultdict(list)
with open(csv_file, newline="") as f:
    rdr = csv.DictReader(f)
    for row in rdr:
        th = int(row["Количество потоков"])
        tm = float(row["время"])
        acc[th].append(tm)

# рисуем среднее время
threads = sorted(acc.keys())
avg_times = [sum(acc[t])/len(acc[t]) for t in threads]

plt.figure()
plt.plot(threads, avg_times, marker="o")
plt.xlabel("Количество потоков")
plt.ylabel("Среднее время, мс")
plt.title("Скорость генерации неидеального лабиринта")
plt.grid(True)
plt.tight_layout()
plt.savefig(out_png)