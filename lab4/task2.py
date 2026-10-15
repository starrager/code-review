import random
from typing import List, Tuple

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


# FIXME: списочное выражение компактнее многострочного цикла, нет аннотации типа для questions

# # Генерация 5 случайных примеров на умножение
# questions = []
# for _ in range(5):
#     a = random.randint(2, 9)
#     b = random.randint(2, 9)
#     questions.append((a, b))

# FIXTO:
# Генерация 5 случайных примеров на умножение
QUESTIONS_COUNT: int = 5
questions: List[Tuple[int, int]] = [
    (random.randint(2, 9), random.randint(2, 9)) for _ in range(QUESTIONS_COUNT)
]

def generate_questions(count: int = 5) -> List[Tuple[int, int]]:
    # Генерация случайных примеров на умножение
    return [(random.randint(2, 9), random.randint(2, 9)) for _ in range(count)]



# FIXME : код должен быть внутри отдельной функции
# user_answers = []
#
# # Выводим вопросы и ответы
# for i, (a, b) in enumerate(questions, 1):
#     answer = input(f"{i}. {a} × {b} = ")
#     user_answers.append(answer)

# FIXTO:
def get_user_answers(questions: List[Tuple[int, int]]) -> List[str]:
    # Ввод ответов пользователя на все вопросы
    user_answers: List[str] = []
    for i, (a, b) in enumerate(questions, 1):
        answer = input(f"{i}. {a} × {b} = ")
        user_answers.append(answer)
    return user_answers


# FIXME: код должен быть внутри отдельной функции, есть длинные строки
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
    questions: List[Tuple[int, int]], user_answers: List[str]) -> int:
    # Проверка ответов и вывод результатов
    print("\n" + "=" * 30)
    print("РЕЗУЛЬТАТЫ:")
    print("=" * 30)

    correct_count: int = 0

    for i, ((a, b), user_ans) in enumerate(zip(questions, user_answers), 1):
        correct: int = a * b

        try:
            user_num: int = int(user_ans)
            if user_num == correct:
                print(f"{i}. {a} × {b} = {correct} ✓")
                correct_count += 1
            else:
                print(f"{i}. {a} × {b} = {RED}{user_ans}{RESET} "
                      f"(правильно: {correct})")
        except ValueError:
            print(f"{i}. {a} × {b} = {RED}{user_ans}{RESET} "
                  f"(нужно число, правильно: {correct})")

    print("\n" + "=" * 30)
    print(f"Правильных ответов: {correct_count} из 5")
    print("=" * 30)

    return correct_count

# Основная функция программы.
def main() -> None:
    print("\n=== ТЕСТ: ТАБЛИЦА УМНОЖЕНИЯ ===\n")

    questions_list: List[Tuple[int, int]] = generate_questions()
    user_answers_list: List[str] = get_user_answers(questions_list)
    check_answers(questions_list, user_answers_list)

if __name__ == "__main__":
    main()

