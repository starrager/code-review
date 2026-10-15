# FIXME: 1. Строки длиннее 80 символов (строки 12, 20, 36, 49, 62).
# FIXME: 2. Нет docstring (описания модуля и функций).
# FIXME: 3. Однобуквенные имена (k, c), имя data неинформативно.
# FIXME: 4. Код на уровне модуля: нет функций, main и
#        if __name__ == '__main__', все переменные глобальные.
# FIXME: 5. Нет аннотаций типов.


# # Проверка ввода количества стран
# while True:
#     try:
#         k = int(input("Введите количество стран: "))
#         if k <= 0:
#             print("Ошибка: количество стран должно быть положительным числом. Попробуйте снова.")
#             continue
#         break
#     except ValueError:
#         print("Ошибка: введите целое число. Попробуйте снова.")

# data = {}

# # Ввод стран и городов
# for i in range(k):
#     print(f"\n Страна {i+1} из {k}")
#     while True:
#         parts = input("Введите страну и города через пробел (пример: Россия Москва СПб Казань): ").strip().split()
#         if len(parts) < 2:
#             print("Ошибка: нужно указать страну и хотя бы один город. Попробуйте снова.")
#             continue

#         country = parts[0]
#         cities = parts[1:]

#         # Проверка, что название страны не пустое
#         if not country:
#             print("Ошибка: название страны не может быть пустым.")
#             continue

#         # Проверка, что все города не пустые
#         if any(not city for city in cities):
#             print("Ошибка: название города не может быть пустым.")
#             continue

#         # Приводим к нижнему регистру и записываем
#         country_lower = country.lower()
#         for c in cities:
#             city_lower = c.lower()
#             if city_lower in data:
#                 print(f"Предупреждение: город '{c}' уже был привязан к стране '{data[city_lower]}'. Будет перезаписан на '{country}'.")
#             data[city_lower] = country_lower
#         break

# print("ТЕПЕРЬ ВВЕДИТЕ 3 ГОРОДА ДЛЯ ПОИСКА")

# for i in range(1, 4):
#     while True:
#         city = input(f"{i} город: ").strip()
#         if not city:
#             print("Ошибка: название города не может быть пустым. Попробуйте снова.")
#             continue

#         city_lower = city.lower()

#         if city_lower in data:
#             # Находим оригинальное написание страны (первое попавшееся)
#             country_found = data[city_lower]
#             print(f"Город '{city}' расположен в стране '{country_found.title()}'.")
#         else:
#             print(f"По городу '{city}' данных нет.")
#         break


# FIXTO:
"""Поиск страны по городу.

Программа запрашивает страны со списками городов, а затем по трём
введённым городам сообщает, в какой стране они находятся.
"""

SEARCH_CITIES_COUNT: int = 3


def input_countries_count() -> int:
    """Запрашивает количество стран.

    Ввод повторяется, пока не будет введено положительное целое число.

    Returns:
        Количество стран.
    """
    while True:
        try:
            countries_count = int(input("Введите количество стран: "))
            if countries_count <= 0:
                print(
                    "Ошибка: количество стран должно быть положительным "
                    "числом. Попробуйте снова."
                )
                continue
            return countries_count
        except ValueError:
            print("Ошибка: введите целое число. Попробуйте снова.")


def add_country(city_to_country: dict[str, str]) -> None:
    """Запрашивает страну со списком городов и записывает их в словарь.

    Формат ввода: страна и хотя бы один город через пробел. Названия
    хранятся в нижнем регистре. Если город уже есть в словаре, выводится
    предупреждение, а страна перезаписывается.

    Args:
        city_to_country: словарь соответствия город -> страна.
    """
    while True:
        user_input = input(
            "Введите страну и города через пробел "
            "(пример: Россия Москва СПб Казань): "
        ).strip()
        parts = user_input.split()

        if len(parts) < 2:
            print(
                "Ошибка: нужно указать страну и хотя бы один город. "
                "Попробуйте снова."
            )
            continue

        country = parts[0]
        country_lower = country.lower()
        for city in parts[1:]:
            city_lower = city.lower()
            if city_lower in city_to_country:
                print(
                    f"Предупреждение: город '{city}' уже был привязан к "
                    f"стране '{city_to_country[city_lower]}'. "
                    f"Будет перезаписан на '{country}'."
                )
            city_to_country[city_lower] = country_lower
        return


def search_cities(city_to_country: dict[str, str]) -> None:
    """Ищет страны для трёх городов, введённых пользователем.

    Поиск выполняется без учёта регистра. Если город не найден,
    выводится сообщение об отсутствии данных.

    Args:
        city_to_country: словарь соответствия город -> страна.
    """
    print("\nТЕПЕРЬ ВВЕДИТЕ 3 ГОРОДА ДЛЯ ПОИСКА")

    for i in range(1, SEARCH_CITIES_COUNT + 1):
        while True:
            city = input(f"{i} город: ").strip()

            if not city:
                print(
                    "Ошибка: название города не может быть пустым. "
                    "Попробуйте снова."
                )
                continue

            city_lower = city.lower()

            if city_lower in city_to_country:
                country_found = city_to_country[city_lower]
                print(
                    f"Город '{city}' расположен в стране "
                    f"'{country_found.title()}'."
                )
            else:
                print(f"По городу '{city}' данных нет.")
            break


def main() -> None:
    """Запускает программу: ввод стран и городов, затем поиск."""
    countries_count = input_countries_count()
    city_to_country: dict[str, str] = {}

    for i in range(countries_count):
        print(f"\nСтрана {i + 1} из {countries_count}")
        add_country(city_to_country)

    search_cities(city_to_country)


if __name__ == '__main__':
    main()
