# FIXME: 1. Длина строк превышает 90 символов.
# FIXME: 2. Отсутствует docstring.
# FIXME: 3. Нарушены соглашения об именовании.
# FIXME: 4. Нет  XML документации.
# FIXME: 5. Отсутствует docstring у функции get_height.


# print("ГЕНЕАЛОГИЧЕСКОЕ ДРЕВО")
# # Проверка ввода количества человек
# while True:
#     try:
#         N = int(input("Введите количество человек: "))
#         if N <= 0:
#             print("Ошибка: количество человек должно быть положительным числом.")
#             continue
#         break
#     except ValueError:
#         print("Ошибка: введите целое число.")

# # Словарь для хранения родителя каждого человека: {потомок: родитель}
# parent = {}

# # Ввод N-1 пары
# for i in range(1, N):
#     while True:
#         pair = input(f"{i} пара: ").strip().split()
#         if len(pair) != 2:
#             print("Ошибка: введите имя потомка и имя родителя через пробел.")
#             continue
        
#         child, parent_name = pair
        
#         # Проверка, что имена не пустые
#         if not child or not parent_name:
#             print("Ошибка: имена не могут быть пустыми.")
#             continue
        
#         # Проверка, что потомок ещё не имеет родителя
#         if child in parent:
#             print(f"Ошибка: для {child} уже указан родитель ({parent[child]}).")
#             continue
        
#         parent[child] = parent_name
#         break

# # Функция для вычисления высоты человека
# def get_height(person, heights_cache):
#     if person in heights_cache:
#         return heights_cache[person]
    
#     # Если у человека нет родителя, значит это родоначальник
#     if person not in parent:
#         heights_cache[person] = 0
#         return 0
    
#     # Высота = высота родителя + 1
#     height = get_height(parent[person], heights_cache) + 1
#     heights_cache[person] = height
#     return height

# # Словарь для кэширования высот
# heights = {}

# # Вычисляем высоту для всех людей
# # Сначала находим всех людей (родители могут не быть в parent как потомки)
# all_people = set(parent.keys()) | set(parent.values())

# # Вычисляем высоту для каждого человека
# for person in all_people:
#     get_height(person, heights)

# # Вывод результатов в лексикографическом порядке
# print("“Высота” каждого члена семьи:")

# for person in sorted(all_people):
#     print(f"{person} {heights[person]}")



#FIXTO:

# Проверка ввода количества людей.
# Пользователь должен ввести положительное целое число.
while True:
    try:
        people_count = int(input("Введите количество человек: "))
        if people_count <= 0:
            print(
                "Ошибка: количество человек должно быть положительным числом. "
                "Попробуйте снова."
            )
            continue
        break
    except ValueError:
        print("Ошибка: введите целое число.")


# Словарь родственных связей.
# child -> parent
parent_map = {}


# Ввод пар (ребёнок -> родитель)
for i in range(1, people_count):
    while True:
        pair = input(f"{i} пара: ").strip().split()

        if len(pair) != 2:
            print("Ошибка: введите 'ребёнок родитель'.")
            continue

        child, parent_name = pair

        if not child or not parent_name:
            print("Ошибка: имена не могут быть пустыми.")
            continue

        if child in parent_map:
            print(
                f"Ошибка: для {child} уже задан родитель "
                f"({parent_map[child]})."
            )
            continue

        parent_map[child] = parent_name
        break


# Словарь высот (кэш).
# person -> height
heights_cache = {}


# Вычисление высоты
# Рекурсивно вычисляет высоту человека в генеалогическом дереве.
# Корневой предок имеет высоту 0.

def get_height(person, cache):
    """
    Вычисляет высоту узла в генеалогическом дереве.

    Args:
        person: имя человека
        cache: словарь кэшированных значений

    Returns:
        int: высота человека в дереве
    """
    if person in cache:
        return cache[person]

    if person not in parent_map:
        cache[person] = 0
        return 0

    height = get_height(parent_map[person], cache) + 1
    cache[person] = height
    return height


# Получаем всех людей
all_people = set(parent_map.keys()) | set(parent_map.values())


# Вычисление высот
for person in all_people:
    get_height(person, heights_cache)


print("\nРезультаты:")

# Вывод по алфавиту
for person in sorted(all_people):
    print(f"{person} {heights_cache[person]}")