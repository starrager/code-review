# FIXME: 1. Строки длиннее 80 символов.
# FIXME: 2. Нет docstring у модуля, а у get_height он был только в
#        FIXTO-версии.
# FIXME: 3. Однобуквенное имя N, имя parent неинформативно.
# FIXME: 4. Нет аннотаций типов.
# FIXME: 5. Код на уровне модуля: нет main и
#        if __name__ == '__main__', глобальные переменные.
# FIXME: 6. Функция get_height использует глобальную parent вместо
#        параметра.


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


# FIXTO:
"""Генеалогическое дерево.

Программа читает пары «потомок родитель» и вычисляет «высоту» каждого
члена семьи: у родоначальника она равна 0, у потомка - высота
родителя плюс 1.
"""


def input_people_count() -> int:
    """Запрашивает количество человек.

    Ввод повторяется, пока не будет введено положительное целое число.

    Returns:
        Количество человек.
    """
    while True:
        try:
            people_count = int(input("Введите количество человек: "))
            if people_count <= 0:
                print(
                    "Ошибка: количество человек должно быть положительным "
                    "числом. Попробуйте снова."
                )
                continue
            return people_count
        except ValueError:
            print("Ошибка: введите целое число.")


def input_parent_map(people_count: int) -> dict[str, str]:
    """Запрашивает пары «потомок родитель» (их на одну меньше людей).

    Args:
        people_count: количество человек в дереве.

    Returns:
        Словарь потомок -> родитель.
    """
    parent_map: dict[str, str] = {}

    for i in range(1, people_count):
        while True:
            pair = input(f"{i} пара: ").strip().split()

            if len(pair) != 2:
                print("Ошибка: введите 'ребёнок родитель'.")
                continue

            child, parent_name = pair

            if child in parent_map:
                print(
                    f"Ошибка: для {child} уже задан родитель "
                    f"({parent_map[child]})."
                )
                continue

            parent_map[child] = parent_name
            break

    return parent_map


def get_height(
    person: str, parent_map: dict[str, str], cache: dict[str, int]
) -> int:
    """Вычисляет высоту человека в генеалогическом дереве.

    Высота родоначальника равна 0, высота остальных - высота
    родителя плюс 1. Результаты сохраняются в кэше.

    Args:
        person: имя человека.
        parent_map: словарь потомок -> родитель.
        cache: словарь уже вычисленных высот.

    Returns:
        Высота человека в дереве.
    """
    if person in cache:
        return cache[person]

    if person not in parent_map:
        cache[person] = 0
        return 0

    height = get_height(parent_map[person], parent_map, cache) + 1
    cache[person] = height
    return height


def print_heights(parent_map: dict[str, str]) -> None:
    """Вычисляет и выводит высоты всех людей по алфавиту.

    Args:
        parent_map: словарь потомок -> родитель.
    """
    heights_cache: dict[str, int] = {}
    all_people = set(parent_map.keys()) | set(parent_map.values())

    for person in all_people:
        get_height(person, parent_map, heights_cache)

    print("\nРезультаты:")

    for person in sorted(all_people):
        print(f"{person} {heights_cache[person]}")


def main() -> None:
    """Запускает программу: ввод дерева и вывод высот."""
    print("ГЕНЕАЛОГИЧЕСКОЕ ДРЕВО")
    people_count = input_people_count()
    parent_map = input_parent_map(people_count)
    print_heights(parent_map)


if __name__ == '__main__':
    main()
