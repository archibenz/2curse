import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.tsa.arima.model import ARIMA
from statsmodels.tsa.stattools import adfuller
import numpy as np
from statsmodels.graphics.tsaplots import plot_acf, plot_pacf

# Загрузка данных
data = pd.read_csv('smartthings.csv')

# Преобразуем столбец TIME в datetime формат
data['TIME'] = pd.to_datetime(data['TIME'], unit='s', errors='coerce')

# Фильтруем данные только за 10 октября 2016 года
data_filtered = data[data['TIME'].dt.date == pd.to_datetime('2016-10-10').date()]

# Устанавливаем столбец TIME как индекс
data_filtered.set_index('TIME', inplace=True)

# Ресэмплинг данных по минутам (считаем количество пакетов по минутам)
data_resampled = data_filtered.resample('T').size()

# Функция для применения теста Дики-Фуллера
def adf_test(series):
    if len(series) >= 10:
        result = adfuller(series.dropna())
        return result[1]  # Возвращаем p-value
    else:
        return None

# Применяем тест на стационарность
p_values = data_resampled.rolling(window=10).apply(adf_test, raw=False)
non_stationary_data = data_resampled[p_values > 0.05]

# Графики ACF и PACF
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
plot_acf(non_stationary_data.dropna(), lags=40, ax=plt.gca())
plt.title('Автокорреляционная функция (ACF)')
plt.subplot(1, 2, 2)
plot_pacf(non_stationary_data.dropna(), lags=40, ax=plt.gca())
plt.title('Частичная автокорреляционная функция (PACF)')
plt.tight_layout()
plt.show()

# Сравнительный анализ нескольких моделей ARIMA
aic_values = []
mape_values = []

# Пробуем разные комбинации параметров (p, d, q)
for p in range(1, 6):
    for d in range(1, 2):
        for q in range(1, 6):
            try:
                model = ARIMA(non_stationary_data.dropna(), order=(p, d, q))
                model_fit = model.fit()
                y_pred = model_fit.predict(start=0, end=len(non_stationary_data.dropna()) - 1)

                # Вычисляем MAPE
                mape = np.mean(np.abs((non_stationary_data.dropna() - y_pred) / non_stationary_data.dropna()))
                aic_values.append((p, d, q, model_fit.aic))
                mape_values.append((p, d, q, mape))
            except Exception as e:
                continue

# Сортируем по AIC
sorted_aic = sorted(aic_values, key=lambda x: x[3])
sorted_mape = sorted(mape_values, key=lambda x: x[3])

# Печатаем лучшие модели с минимальным AIC и MAPE
print("Сравнительный анализ AIC:")
for p, d, q, aic in sorted_aic:
    print(f"Модель ARIMA({p}, {d}, {q}) - AIC: {aic}")

print("\nСравнительный анализ MAPE:")
for p, d, q, mape in sorted_mape:
    print(f"Модель ARIMA({p}, {d}, {q}) - MAPE: {mape}%")

# Строим модель с наименьшим AIC
best_p, best_d, best_q = sorted_aic[0][0], sorted_aic[0][1], sorted_aic[0][2]
print(f"\nЛучшая модель ARIMA: ARIMA({best_p}, {best_d}, {best_q})")

# Разделение данных на обучающую и тестовую выборки
train_data = non_stationary_data[:'2016-10-10 22:00:00']
test_data = non_stationary_data['2016-10-10 22:00:00':]

# Обучение лучшей модели ARIMA на обучающей выборке
best_model = ARIMA(train_data.dropna(), order=(best_p, best_d, best_q))
best_model_fit = best_model.fit()

# Прогноз на тестовой выборке
y_pred = best_model_fit.forecast(steps=len(test_data))

# Визуализация
plt.figure(figsize=(12, 6))

# Исторические данные (обучающая выборка)
plt.plot(train_data.index, train_data, label='Обучающая выборка', color='blue')

# Исторические данные (тестовая выборка)
plt.plot(test_data.index, test_data, label='Тестовая выборка', color='green')

# Предсказания ARIMA
plt.plot(test_data.index, y_pred, label=f'Прогноз ARIMA({best_p}, {best_d}, {best_q})', color='red', linestyle='--')

# Настройка графика
plt.title('Прогноз активности Интернет вещей (IoT) с использованием ARIMA')
plt.xlabel('Время')
plt.ylabel('Количество пакетов')
plt.legend()
plt.grid()

# Показываем график
plt.show()
