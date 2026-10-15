# FIXME: 1. Длина строки превышает 90 символов (строки: 12, 20, 36, 49, 62).
# FIXME: 2. Отсутствуют docstring (нет документации).
# FIXME: 3. Нарушены соглашения об именовании (snake_case, не описательные).
# FIXME: 4. Нет XML-документации перед основными блоками (перед вводом стран, перед вводом городов для поиска).



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

#  Проверка ввода количества стран.
#  Пользователь обязан ввести положительное целое число.
#  При некорректном вводе запрос повторяется.
while True:
    try:
        countries_count = int(input("Введите количество стран: "))
        if countries_count <= 0:
            print(
                "Ошибка: количество стран должно быть положительным числом. "
                "Попробуйте снова."
            )
            continue
        break
    except ValueError:
        print("Ошибка: введите целое число. Попробуйте снова.")

#  Словарь соответствия город -> страна.
#  key: город (lowercase)
#  value: страна (lowercase)
city_to_country = {}


# Ввод стран и городов.
# Формат ввода: страна + список городов.
# Минимум один город обязателен.
# Выполняется проверка на пустые значения и дубликаты городов.
for i in range(countries_count):
    print(f"\nСтрана {i + 1} из {countries_count}")

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
        cities = parts[1:]

        # Проверка, что название страны не пустое
        if not country:
            print("Ошибка: название страны не может быть пустым.")
            continue

        # Проверка, что все города не пустые
        if any(not city for city in cities):
            print("Ошибка: название города не может быть пустым.")
            continue

        # Приводим к нижнему регистру и записываем
        country_lower = country.lower()
        for city in cities:
            city_lower = city.lower()
            if city_lower in city_to_country:
                print(
                    f"Предупреждение: город '{city}' уже был привязан к стране "
                    f"'{city_to_country[city_lower]}'. Будет перезаписан на "
                    f"'{country}'."
                )
            city_to_country[city_lower] = country_lower
        break

print("\nТЕПЕРЬ ВВЕДИТЕ 3 ГОРОДА ДЛЯ ПОИСКА")


# Блок поиска.
# Пользователь вводит 3 города.
# Выполняется поиск страны без учёта регистра.
# Если город не найден - выводится сообщение об отсутствии данных.
for i in range(1, 4):
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