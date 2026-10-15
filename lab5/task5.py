# FIXME: 1. Строки длиннее 80 символов.
# FIXME: 2. Нет docstring (описания модуля и функций).
# FIXME: 3. Однобуквенные имена (f, e), сокращения ru / en.
# FIXME: 4. Код на уровне модуля: нет функций, main и
#        if __name__ == '__main__', глобальные переменные.
# FIXME: 5. Нет аннотаций типов, нет документирования логики проверки.
# FIXME: 6. Проверка len(x) == 0 вместо `if not x`, exit(1) вместо
#        sys.exit(1), слишком широкий except Exception.


# import os

# print("ПРОГРАММА ТЕСТИРОВАНИЯ ПЕРЕВОДОВ")
# # Проверка наличия файлов
# russian_file = "input.txt"
# english_file = "output.txt"

# if not os.path.exists(russian_file):
#     print(f"Ошибка: Файл '{russian_file}' не найден!")
#     print("Создайте файл с русскими словами (по одному на строку).")
#     exit(1)

# if not os.path.exists(english_file):
#     print(f"Ошибка: Файл '{english_file}' не найден!")
#     print("Создайте файл с английскими переводами (по одному на строку).")
#     exit(1)

# # Чтение слов из файлов
# try:
#     with open(russian_file, 'r', encoding='utf-8') as f:
#         russian_words = [line.strip() for line in f if line.strip()]

#     with open(english_file, 'r', encoding='utf-8') as f:
#         english_words = [line.strip() for line in f if line.strip()]

#     # Проверка, что количество строк совпадает
#     if len(russian_words) != len(english_words):
#         print(f"\nПредупреждение: Количество слов не совпадает!")
#         print(f"Русских слов: {len(russian_words)}")
#         print(f"Английских переводов: {len(english_words)}")
#         print("Тестирование будет проведено только для меньшего количества.")

#         min_len = min(len(russian_words), len(english_words))
#         russian_words = russian_words[:min_len]
#         english_words = english_words[:min_len]

# except Exception as e:
#     print(f"Ошибка при чтении файлов: {e}")
#     exit(1)

# if len(russian_words) == 0:
#     print("Ошибка: Файлы пусты или не содержат корректных данных.")
#     exit(1)

# print(f"\nЗагружено {len(russian_words)} слов для тестирования.")
# print()
# print("НАЧАЛО ТЕСТИРОВАНИЯ")


# # Переменные для подсчета правильных ответов
# correct_answers = 0
# total_questions = len(russian_words)

# # Тестирование
# for i, (russian, correct_english) in enumerate(zip(russian_words, english_words), 1):
#     print(f"\nВопрос {i}/{total_questions}:")
#     print(f"Русское слово: {russian}")

#     user_answer = input("Ваш перевод на английский: ").strip().lower()

#     # Сравниваем, игнорируя регистр и лишние пробелы
#     if user_answer == correct_english.lower():
#         print("Верно!")
#         correct_answers += 1
#     else:
#         print(f"Неверно!")
#         print(f"Правильный перевод: {correct_english}")

# # Вывод оценки
# print("РЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ")
# percentage = (correct_answers / total_questions) * 100

# print(f"\nПравильных ответов: {correct_answers} из {total_questions}")
# print(f"Процент правильных ответов: {percentage:.1f}%")

# # Выставление оценки
# if percentage >= 90:
#     grade = "5 (Отлично)"
#     print("\n ОТЛИЧНО! Вы знаете английский на высоком уровне!")
# elif percentage >= 75:
#     grade = "4 (Хорошо)"
#     print("\n ХОРОШО! Неплохой результат, но есть куда расти!")
# elif percentage >= 60:
#     grade = "3 (Удовлетворительно)"
#     print("\n УДОВЛЕТВОРИТЕЛЬНО. Нужно ещё немного подучить слова!")
# elif percentage >= 30:
#     grade = "2 (Неудовлетворительно)"
#     print("\n НЕУДОВЛЕТВОРИТЕЛЬНО. Слова нужно учить лучше!")
# else:
#     grade = "1 (Плохо)"
#     print("\n ПЛОХО. Вам стоит серьезно заняться изучением английского!")

# print(f"\nОценка: {grade}")


# FIXTO:
"""Тестирование знания английских переводов.

Программа читает русские слова и их английские переводы из файлов,
проводит интерактивный тест и выставляет оценку.
"""

import os
import sys

RUSSIAN_FILE: str = "input.txt"
ENGLISH_FILE: str = "output.txt"


def read_words(file_path: str) -> list[str]:
    """Читает слова из файла, пропуская пустые строки.

    Args:
        file_path: путь к файлу (по одному слову на строку).

    Returns:
        Список слов без пробелов по краям.
    """
    with open(file_path, "r", encoding="utf-8") as file:
        return [line.strip() for line in file if line.strip()]


def load_words() -> tuple[list[str], list[str]]:
    """Проверяет наличие файлов и загружает русские и английские слова.

    Если количество слов не совпадает, списки обрезаются до длины
    меньшего. При ошибке программа завершается с кодом 1.

    Returns:
        Кортеж (русские слова, английские переводы).
    """
    for file_path in (RUSSIAN_FILE, ENGLISH_FILE):
        if not os.path.exists(file_path):
            print(f"Ошибка: файл '{file_path}' не найден!")
            sys.exit(1)

    try:
        russian_words = read_words(RUSSIAN_FILE)
        english_words = read_words(ENGLISH_FILE)
    except (OSError, UnicodeDecodeError) as error:
        print(f"Ошибка чтения файлов: {error}")
        sys.exit(1)

    if len(russian_words) != len(english_words):
        print("Предупреждение: количество слов не совпадает.")
        min_length = min(len(russian_words), len(english_words))
        russian_words = russian_words[:min_length]
        english_words = english_words[:min_length]

    if not russian_words:
        print("Ошибка: файлы пустые.")
        sys.exit(1)

    return russian_words, english_words


def check_answer(user_answer: str, correct_answer: str) -> bool:
    """Проверяет ответ пользователя без учёта регистра и пробелов.

    Args:
        user_answer: ответ пользователя.
        correct_answer: правильный перевод.

    Returns:
        True, если ответ верный.
    """
    return user_answer.strip().lower() == correct_answer.strip().lower()


def run_quiz(russian_words: list[str], english_words: list[str]) -> int:
    """Проводит тест и считает правильные ответы.

    Args:
        russian_words: русские слова.
        english_words: правильные английские переводы.

    Returns:
        Количество правильных ответов.
    """
    total_questions = len(russian_words)
    correct_answers = 0
    questions = zip(russian_words, english_words)

    for i, (russian_word, english_word) in enumerate(questions, 1):
        print(f"\nВопрос {i}/{total_questions}")
        print(f"Русское слово: {russian_word}")

        user_answer = input("Перевод: ")

        if check_answer(user_answer, english_word):
            print("Верно!")
            correct_answers += 1
        else:
            print("Неверно!")
            print(f"Правильный ответ: {english_word}")

    return correct_answers


def get_grade(percentage: float) -> str:
    """Переводит процент правильных ответов в оценку.

    Args:
        percentage: процент правильных ответов (0-100).

    Returns:
        Оценка от "1" до "5".
    """
    if percentage >= 90:
        return "5"
    if percentage >= 75:
        return "4"
    if percentage >= 60:
        return "3"
    if percentage >= 30:
        return "2"
    return "1"


def print_results(correct_answers: int, total_questions: int) -> None:
    """Выводит результаты теста и оценку.

    Args:
        correct_answers: количество правильных ответов.
        total_questions: общее количество вопросов.
    """
    percentage = correct_answers / total_questions * 100

    print("\nРЕЗУЛЬТАТЫ")
    print(f"Правильных: {correct_answers}/{total_questions}")
    print(f"Процент: {percentage:.1f}%")
    print(f"Оценка: {get_grade(percentage)}")


def main() -> None:
    """Запускает программу тестирования переводов."""
    print("ПРОГРАММА ТЕСТИРОВАНИЯ ПЕРЕВОДОВ")
    russian_words, english_words = load_words()

    print(f"Загружено {len(russian_words)} слов.")
    print("НАЧАЛО ТЕСТИРОВАНИЯ")

    correct_answers = run_quiz(russian_words, english_words)
    print_results(correct_answers, len(russian_words))


if __name__ == '__main__':
    main()
