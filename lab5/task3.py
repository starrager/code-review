# FIXME: 1. Строки длиннее 80 символов.
# FIXME: 2. Нет docstring (описания модуля и функций).
# FIXME: 3. Нарушены соглашения об именовании (N - однобуквенное имя
#        и не константа, num).
# FIXME: 4. Нет аннотаций типов.
# FIXME: 5. Код на уровне модуля: нет функций, main и
#        if __name__ == '__main__', длинный цикл, глобальные переменные.
# FIXME: 6. Проверка len(x) == 0 вместо `if not x`.


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
"""Игра «Угадайка».

Программа сужает множество возможных чисел от 1 до максимального
на основе ответов «да» / «нет» и определяет загаданное число
методом исключения.
"""

HELP_COMMAND: str = "помогите!"


def input_max_number() -> int:
    """Запрашивает максимальное загаданное число.

    Ввод повторяется, пока не будет введено натуральное число.

    Returns:
        Максимальное число (больше нуля).
    """
    while True:
        try:
            max_number = int(input("Введите максимальное число: "))
            if max_number <= 0:
                print(
                    "Ошибка: число должно быть натуральным (больше 0). "
                    "Попробуйте снова."
                )
                continue
            return max_number
        except ValueError:
            print("Ошибка: введите целое число. Попробуйте снова.")


def parse_numbers(text: str, max_number: int) -> set[int] | None:
    """Преобразует строку с числами в множество и проверяет диапазон.

    Args:
        text: строка с числами через пробел.
        max_number: максимально допустимое число.

    Returns:
        Множество чисел или None, если ввод некорректен
        (сообщение об ошибке уже выведено).
    """
    guessed_numbers: set[int] = set()

    for part in text.split():
        try:
            number = int(part)
        except ValueError:
            print(
                f"Ошибка: '{part}' не является числом. "
                "Введите числа через пробел."
            )
            return None

        if number < 1 or number > max_number:
            print(
                f"Ошибка: число {number} вне диапазона "
                f"(1..{max_number}). Попробуйте снова."
            )
            return None

        guessed_numbers.add(number)

    return guessed_numbers


def input_answer() -> str:
    """Запрашивает ответ Ивана: «да» или «нет».

    Returns:
        Ответ в нижнем регистре ("да" или "нет").
    """
    while True:
        answer = input("Ответ Ивана: ").strip().lower()

        if answer in ("да", "нет"):
            return answer

        print("Ошибка: введите 'Да' или 'Нет'.")


def play(max_number: int) -> set[int]:
    """Проводит игру и возвращает оставшиеся возможные числа.

    Игра заканчивается, если пользователь ввёл команду «помогите!»,
    ответы противоречат друг другу или остался один вариант.

    Args:
        max_number: максимальное загаданное число.

    Returns:
        Множество чисел, которые мог загадать Иван.
    """
    possible_numbers: set[int] = set(range(1, max_number + 1))

    print("НАЧАЛО ИГРЫ")

    while True:
        user_input = input(
            "\nНужное число есть среди вот этих чисел: "
        ).strip()

        if user_input.lower() == HELP_COMMAND:
            break

        guessed_numbers = parse_numbers(user_input, max_number)
        if guessed_numbers is None:
            continue

        if not guessed_numbers:
            print("Ошибка: введите хотя бы одно число.")
            continue

        if input_answer() == "да":
            possible_numbers &= guessed_numbers
        else:
            possible_numbers -= guessed_numbers

        if not possible_numbers:
            print("\nПротиворечие! Нет подходящих чисел.")
            break

        if len(possible_numbers) == 1:
            (number,) = possible_numbers
            print(f"\nСергей угадал число! Это число: {number}")
            break

    return possible_numbers


def print_result(possible_numbers: set[int]) -> None:
    """Выводит итоговый результат игры.

    Args:
        possible_numbers: числа, которые мог загадать Иван.
    """
    print("РЕЗУЛЬТАТ:")

    if possible_numbers:
        sorted_numbers = sorted(possible_numbers)
        print(
            "Иван мог загадать следующие числа: "
            f"{' '.join(map(str, sorted_numbers))}"
        )
    else:
        print("Нет возможных чисел. Противоречивые ответы Ивана.")


def main() -> None:
    """Запускает игру «Угадайка»."""
    print("ИГРА «УГАДАЙКА»")
    max_number = input_max_number()
    possible_numbers = play(max_number)
    print_result(possible_numbers)


if __name__ == '__main__':
    main()
