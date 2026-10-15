# FIXME: 1. Длина строки превышает 90 символов
# FIXME: 2. Отсутствует docstring для модуля (нет общего описания программы).
# FIXME: 3. Нарушены соглашения об именовании.
# FIXME: 4. Нет type hints (аннотаций типов для переменных и логики обработки ввода).
# FIXME: 5. Нет XML документирования.


# print("ИГРА «УГАДАЙКА»")
# # Проверка ввода максимального числа
# while True:
#     try:
#         N = int(input("Введите максимальное число: "))
#         if N <= 0:
#             print("Ошибка: число должно быть натуральным (больше 0). Попробуйте снова.")
#             continue
#         break
#     except ValueError:
#         print("Ошибка: введите целое число. Попробуйте снова.")

# # Множество возможных чисел (изначально все числа от 1 до N)
# possible_numbers = set(range(1, N + 1))

# print("НАЧАЛО ИГРЫ")

# while True:
#     user_input = input("\n Нужное число есть среди вот этих чисел: ").strip()
    
#     # Проверка, хочет ли пользователь помощи
#     if user_input.lower() == "помогите!":
#         break
    
#     # Разбиваем ввод на числа
#     parts = user_input.split()
#     guessed_numbers = set()
#     valid_input = True
    
#     # Проверяем, что все введенные значения - числа в диапазоне 1..N
#     for part in parts:
#         try:
#             num = int(part)
#             if num < 1 or num > N:
#                 print(f"Ошибка: число {num} вне допустимого диапазона (1..{N}). Попробуйте снова.")
#                 valid_input = False
#                 break
#             guessed_numbers.add(num)
#         except ValueError:
#             print(f"Ошибка: '{part}' не является числом. Введите числа через пробел.")
#             valid_input = False
#             break
    
#     if not valid_input:
#         continue
    
#     if not guessed_numbers:
#         print("Ошибка: введите хотя бы одно число.")
#         continue
    
#     # Запрашиваем ответ Ивана
#     while True:
#         answer = input("Ответ Ивана: ").strip().lower()
#         if answer in ["да", "нет"]:
#             break
#         print("Ошибка: введите 'Да' или 'Нет'.")
    
#     # Обновляем множество возможных чисел
#     if answer == "да":
#         # Если ответ "Да", то задуманное число среди названных
#         possible_numbers &= guessed_numbers
#     else:  # answer == "нет"
#         # Если ответ "Нет", то задуманное число НЕ среди названных
#         possible_numbers -= guessed_numbers
    
#     # Проверка, остались ли возможные варианты
#     if len(possible_numbers) == 0:
#         print("\n Противоречие! Нет чисел, удовлетворяющих всем ответам.")
#         break
    
#     # Проверка, не угадано ли число (остался 1 вариант)
#     if len(possible_numbers) == 1:
#         print(f"\n Сергей угадал число! Это число: {list(possible_numbers)[0]}")
#         break

# print("РЕЗУЛЬТАТ:")

# if len(possible_numbers) > 0:
#     # Сортируем числа для красивого вывода
#     sorted_numbers = sorted(possible_numbers)
#     print(f"Иван мог загадать следующие числа: {' '.join(map(str, sorted_numbers))}")
# else:
#     print("Нет возможных чисел. Противоречивые ответы Ивана.")










# FIXTO:


# Игра «Угадайка».

# Программа сужает множество возможных чисел от 1 до N
# на основе ответов пользователя (да/нет) и пытается
# определить загаданное число методом исключения.
# Проверка ввода максимального числа.
# Пользователь должен ввести натуральное число (> 0).
while True:
    try:
        N = int(input("Введите максимальное число: "))
        if N <= 0:
            print(
                "Ошибка: число должно быть натуральным (больше 0). "
                "Попробуйте снова."
            )
            continue
        break
    except ValueError:
        print("Ошибка: введите целое число. Попробуйте снова.")


# Множество возможных чисел.
# Изначально: все числа от 1 до N.
possible_numbers = set(range(1, N + 1))


print("НАЧАЛО ИГРЫ")
# Основной игровой цикл.
# Пользователь вводит числа или команду "помогите!"
while True:
    user_input = input(
        "\nНужное число есть среди вот этих чисел: "
    ).strip()

    if user_input.lower() == "помогите!":
        break

    parts = user_input.split()
    guessed_numbers = set()
    valid_input = True

    # Проверка введённых чисел
    for part in parts:
        try:
            num = int(part)

            if num < 1 or num > N:
                print(
                    f"Ошибка: число {num} вне диапазона (1..{N}). "
                    "Попробуйте снова."
                )
                valid_input = False
                break

            guessed_numbers.add(num)

        except ValueError:
            print(
                f"Ошибка: '{part}' не является числом. "
                "Введите числа через пробел."
            )
            valid_input = False
            break

    if not valid_input:
        continue

    if not guessed_numbers:
        print("Ошибка: введите хотя бы одно число.")
        continue

    # Ответ пользователя
    while True:
        answer = input("Ответ Ивана: ").strip().lower()

        if answer in ["да", "нет"]:
            break

        print("Ошибка: введите 'Да' или 'Нет'.")

    # Обновление множества возможных чисел
    if answer == "да":
        possible_numbers &= guessed_numbers
    else:
        possible_numbers -= guessed_numbers

    # Проверка на противоречие
    if len(possible_numbers) == 0:
        print("\nПротиворечие! Нет подходящих чисел.")
        break

    # Проверка победы
    if len(possible_numbers) == 1:
        print(
            f"\nСергей угадал число! Это число: "
            f"{list(possible_numbers)[0]}"
        )
        break


print("РЕЗУЛЬТАТ:")


# Финальный вывод
if len(possible_numbers) > 0:
    sorted_numbers = sorted(possible_numbers)

    print(
        "Иван мог загадать следующие числа: "
        f"{' '.join(map(str, sorted_numbers))}"
    )
else:
    print("Нет возможных чисел. Противоречивые ответы Ивана.")