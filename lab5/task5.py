# FIXME: 1. Длина строк превышает 90 символов.
# FIXME: 2. Отсутствует документация (описание программы).
# FIXME: 3. Нарушены соглашения об именовании.
# FIXME: 4. Нет XML-документирования перед основными блоками.
# FIXME: 5. Нет документирования логики функции/алгоритма проверки ответов.


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



#FIXTO:

import os

print("ПРОГРАММА ТЕСТИРОВАНИЯ ПЕРЕВОДОВ")


# Программа выполняет тестирование знания английских переводов.
# Читает русские слова и английские переводы из файлов.
# Проводит интерактивный тест и выставляет оценку.

# Проверка наличия входных файлов перед запуском теста.
RUSSIAN_FILE = "input.txt"
ENGLISH_FILE = "output.txt"

if not os.path.exists(RUSSIAN_FILE):
    print(f"Ошибка: файл '{RUSSIAN_FILE}' не найден!")
    exit(1)

if not os.path.exists(ENGLISH_FILE):
    print(f"Ошибка: файл '{ENGLISH_FILE}' не найден!")
    exit(1)


# Чтение и очистка данных из файлов.
# Удаляются пустые строки.
try:
    with open(RUSSIAN_FILE, "r", encoding="utf-8") as f:
        russian_words = [line.strip() for line in f if line.strip()]

    with open(ENGLISH_FILE, "r", encoding="utf-8") as f:
        english_words = [line.strip() for line in f if line.strip()]

    if len(russian_words) != len(english_words):
        print("Предупреждение: количество слов не совпадает.")

        min_len = min(len(russian_words), len(english_words))
        russian_words = russian_words[:min_len]
        english_words = english_words[:min_len]

except Exception as e:
    print(f"Ошибка чтения файлов: {e}")
    exit(1)


if len(russian_words) == 0:
    print("Ошибка: файлы пустые.")
    exit(1)


print(f"Загружено {len(russian_words)} слов.")
print("НАЧАЛО ТЕСТИРОВАНИЯ")



# Логика проверки ответов пользователя.
# Сравнение без учёта регистра.
correct_answers = 0
total_questions = len(russian_words)


def check_answer(user_answer: str, correct_answer: str) -> bool:
    """
    Проверяет правильность ответа пользователя.

    :param user_answer: ответ пользователя
    :param correct_answer: правильный перевод
    :return: True если ответ верный
    """
    return user_answer.strip().lower() == correct_answer.strip().lower()


for i, (ru, en) in enumerate(zip(russian_words, english_words), 1):
    print(f"\nВопрос {i}/{total_questions}")
    print(f"Русское слово: {ru}")

    user_answer = input("Перевод: ")

    if check_answer(user_answer, en):
        print("Верно!")
        correct_answers += 1
    else:
        print("Неверно!")
        print(f"Правильный ответ: {en}")



# Подсчёт результата и выставление оценки.
percentage = (correct_answers / total_questions) * 100

print("\nРЕЗУЛЬТАТЫ")
print(f"Правильных: {correct_answers}/{total_questions}")
print(f"Процент: {percentage:.1f}%")


if percentage >= 90:
    grade = "5"
elif percentage >= 75:
    grade = "4"
elif percentage >= 60:
    grade = "3"
elif percentage >= 30:
    grade = "2"
else:
    grade = "1"

print(f"Оценка: {grade}")