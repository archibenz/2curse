set terminal png size 800,600
set output 'delivery_time_mm1.png'
set title 'M/M/1: Зависимость времени доставки от интенсивности нагрузки'
set xlabel 'Интенсивность нагрузки (a)'
set ylabel 'Время доставки (T)'
set grid
plot 'results_mm1.dat' using 1:2 with lines title 'Priority 1', \
     'results_mm1.dat' using 1:3 with lines title 'Priority 2', \
     'results_mm1.dat' using 1:4 with lines title 'Priority 3'
