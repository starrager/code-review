import random

# FIXME: нет аннотаций типов для констант
# # ANSI-коды для цвета
# RED = "\033[91m"
# GREEN = "\033[92m"
# RESET = "\033[0m"

# FIXTO:
# ANSI-коды для цвета
RED: str = "\033[91m"
GREEN: str = "\033[92m"
RESET: str = "\033[0m"
QUESTIONS_COUNT: int = 5


# FIXME: списочное выражение компактнее многострочного цикла, нет
#        аннотации типа, глобальная переменная questions, однобуквенные
#        имена (a, b), импорт функций из typing вместо модуля

# # Генерация 5 случайных примеров на умножение
# questions = []
# for _ in range(5):
#     a = random.randint(2, 9)
#     b = random.randint(2, 9)
#     questions.append((a, b))

# FIXTO:
def generate_questions(
    count: int = QUESTIONS_COUNT,
) -> list[tuple[int, int]]:
    # Генерация случайных примеров на умножение
    return [
        (random.randint(2, 9), random.randint(2, 9)) for _ in range(count)
    ]


# FIXME: код должен быть внутри отдельной функции, однобуквенные имена
# user_answers = []
#
# # Выводим вопросы и ответы
# for i, (a, b) in enumerate(questions, 1):
#     answer = input(f"{i}. {a} × {b} = ")
#     user_answers.append(answer)

# FIXTO:
def get_user_answers(questions: list[tuple[int, int]]) -> list[str]:
    # Ввод ответов пользователя на все вопросы
    user_answers: list[str] = []
    for i, (left, right) in enumerate(questions, 1):
        answer = input(f"{i}. {left} × {right} = ")
        user_answers.append(answer)
    return user_answers


# FIXME: код должен быть внутри отдельной функции, есть длинные строки,
#        однобуквенные имена (a, b), число 5 записано в коде вручную
# print("\n" + "=" * 30)
# print("РЕЗУЛЬТАТЫ:")
# print("=" * 30)

# correct_count = 0

# for i, ((a, b), user_ans) in enumerate(zip(questions, user_answers), 1):
#     correct = a * b

#     try:
#         user_num = int(user_ans)
#         if user_num == correct:
#             print(f"{i}. {a} × {b} = {correct} ✓")
#             correct_count += 1
#         else:
#             # Выделяем неправильный ответ красным
#             print(f"{i}. {a} × {b} = {RED}{user_ans}{RESET} (правильно: {correct})")
#     except ValueError:
#         # Если введено не число — тоже ошибка
#         print(f"{i}. {a} × {b} = {RED}{user_ans}{RESET} (нужно число, правильно: {correct})")

# print("\n" + "=" * 30)
# print(f"Правильных ответов: {correct_count} из 5")
# print("=" * 30)


# FIXTO:
def check_answers(
    questions: list[tuple[int, int]], user_answers: list[str]
) -> int:
    # Проверка ответов и вывод результатов
    print("\n" + "=" * 30)
    print("РЕЗУЛЬТАТЫ:")
    print("=" * 30)

    correct_count: int = 0

    for i, ((left, right), user_answer) in enumerate(
        zip(questions, user_answers), 1
    ):
        correct: int = left * right

        try:
            user_num: int = int(user_answer)
            if user_num == correct:
                print(f"{i}. {left} × {right} = {correct} ✓")
                correct_count += 1
            else:
                print(
                    f"{i}. {left} × {right} = {RED}{user_answer}{RESET} "
                    f"(правильно: {correct})"
                )
        except ValueError:
            print(
                f"{i}. {left} × {right} = {RED}{user_answer}{RESET} "
                f"(нужно число, правильно: {correct})"
            )

    print("\n" + "=" * 30)
    print(f"Правильных ответов: {correct_count} из {len(questions)}")
    print("=" * 30)

    return correct_count


# Основная функция программы.
def main() -> None:
    print("\n=== ТЕСТ: ТАБЛИЦА УМНОЖЕНИЯ ===\n")

    questions: list[tuple[int, int]] = generate_questions()
    user_answers: list[str] = get_user_answers(questions)
    check_answers(questions, user_answers)


if __name__ == '__main__':
    main()
