import numpy as np

# Определение русского алфавита, разделенного на группы
alphabet_groups = [
    "абвгд",  # Группа 0
    "еёжзи",  # Группа 1
    "йклмн",  # Группа 2
    "опрст",  # Группа 3
    "уфхцч",  # Группа 4
    "шщъыэюя" # Группа 5
]

# Функция для получения индекса группы буквы
def get_group_index(letter):
    for i, group in enumerate(alphabet_groups):
        if letter in group:
            return i
    return None

# Преобразование имени в массив индексов групп
def convert_name_to_indices(name):
    indices = []
    for letter in name:
        group_index = get_group_index(letter.lower())
        if group_index is not None:
            indices.append(group_index)
    return indices

# Преобразование Фурье
def fourier_transform(indices):
    transformed = np.fft.fft(indices)
    print("Абсолютные значения после FFT:", np.abs(transformed))
    transformed[np.abs(transformed) < 1] = 0  # Обнуление малых значений
    return transformed

# Обратное преобразование Фурье
def inverse_fourier_transform(transformed):
    return np.fft.ifft(transformed).real

# Получение букв для ника с выбором пользователем
def generate_nickname_with_user_input(cleaned_indices):
    nickname = []
    print("\nВыберите буквы для ника из предложенных групп:")
    try:
        for i, group_index in enumerate(cleaned_indices):
            if 0 <= group_index < len(alphabet_groups):
                print(f"Группа {group_index} ({alphabet_groups[group_index]}):")
                while True:
                    chosen_letter = input(f"Выберите букву из группы для позиции {i + 1}: ")
                    if chosen_letter in alphabet_groups[group_index]:
                        nickname.append(chosen_letter)
                        break
                    else:
                        print("Ошибка: выберите букву из предложенной группы.")
            else:
                print("Ошибка: индекс группы некорректен.")
                nickname.append('?')  # Добавление заглушки при ошибке
    except KeyboardInterrupt:
        print("\nПрограмма была прервана пользователем.")
        print("Никнейм не был сгенерирован полностью.")
        return ''.join(nickname)  # Возвращаем частично сформированный ник
    return ''.join(nickname)

# Основная программа
if __name__ == "__main__":
    try:
        # Ввод исходного имени пользователем
        name = input("Введите исходное имя: ")
        
        # Конвертация имени в индексы
        name_indices = convert_name_to_indices(name)
        print(f"Индексы групп: {name_indices}")
        
        # Выполнение FFT
        transformed = fourier_transform(name_indices)
        
        # Выполнение обратного FFT
        recovered_indices = inverse_fourier_transform(transformed)
        cleaned_indices = [int(round(i)) for i in recovered_indices]
        print(f"Очищенные индексы групп: {cleaned_indices}")
        
        # Генерация ника с выбором пользователя
        final_nickname = generate_nickname_with_user_input(cleaned_indices)
        print(f"\nВаш сгенерированный ник: {final_nickname}")
    
    except KeyboardInterrupt:
        print("\nПрограмма была прервана пользователем. Завершение работы.")
