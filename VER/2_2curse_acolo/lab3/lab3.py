# Константы из методички
gamma = 109  # р./усл.т
sigma = 80  # для "Загородного дома отдыха"
F = 5

# Показатели агрессивности (Ai, усл.т/т)
aggressiveness = {
    'CO': 1,
    'CH': 1.5,
    'NOx': 41.1
}

# Удельные выбросы, г/км
emissions_per_km = {
    'gasoline': {'CO': 1.5, 'CH': 13.3, 'NOx': 8},
    'diesel': {'CO': 15, 'CH': 6.4, 'NOx': 8.5}
}

# Коэффициенты влияния
factors = {
    'gasoline': {
        'CO': (1.38, 1.69, 1.2),
        'CH': (1.2, 1.86, 1.2),
        'NOx': (1.0, 0.8, 1.2)
    },
    'diesel': {
        'CO': (1.0, 1.8, 1.2),
        'CH': (1.0, 1.0, 1.2),
        'NOx': (1.0, 1.0, 1.2)
    }
}

# Данные варианта 7
cars = {
    'gasoline': {'count': 23, 'mileage': 18200},
    'diesel': {'count': 9, 'mileage': 29300}
}

def calc_mass_per_type(fuel_type):
    total_mass = {'CO': 0, 'CH': 0, 'NOx': 0}
    total_mileage = cars[fuel_type]['count'] * cars[fuel_type]['mileage']

    for substance in ['CO', 'CH', 'NOx']:
        Mi_ud = emissions_per_km[fuel_type][substance]
        k1, k2, k3 = factors[fuel_type][substance]

        Mi = Mi_ud * total_mileage * k1 * k2 * k3 * 1e-6  # в тоннах
        total_mass[substance] = Mi

    return total_mass

# Расчёт массы выбросов
mass_gasoline = calc_mass_per_type('gasoline')
mass_diesel = calc_mass_per_type('diesel')

# Суммарная масса по всем автомобилям
total_mass = {
    key: mass_gasoline[key] + mass_diesel[key] for key in ['CO', 'CH', 'NOx']
}

# Расчёт приведённой массы M
M = sum(aggressiveness[key] * total_mass[key] for key in ['CO', 'CH', 'NOx'])

# Экономический ущерб
Y = gamma * sigma * F * M

# Вывод
print("Годовой пробег бензиновых авто:", cars['gasoline']['count'] * cars['gasoline']['mileage'], "км")
print("Годовой пробег дизельных авто:", cars['diesel']['count'] * cars['diesel']['mileage'], "км")
print("Масса выбросов, т/год:", total_mass)
print("Приведённая масса выбросов, M =", round(M, 3), "усл.т/год")
print("Экономический ущерб, Y =", round(Y, 2), "руб./год")