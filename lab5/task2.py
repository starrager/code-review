# FIXME: 1. Длина строки превышает 90 символов (строки: 4, 12, 20, 28, 36, 44, 52, 60).
# FIXME: 2. Отсутствуют docstring (нет документации).
# FIXME: 3. Нарушены соглашения об именовании (n, orders - неинформативные имена).
# FIXME: 4. Нет XML-документации перед основными блоками.


# # Проверка ввода количества заказов
# while True:
#     try:
#         n = int(input("Введите кол-во заказов: "))
#         if n <= 0:
#             print("Ошибка: количество заказов должно быть положительным числом. Попробуйте снова.")
#             continue
#         break
#     except ValueError:
#         print("Ошибка: введите целое число. Попробуйте снова.")

# # Словарь для хранения заказов: {покупатель: {пицца: количество}}
# orders = {}

# # Ввод заказов
# for i in range(1, n + 1):
#     while True:
#         order = input(f"{i} заказ: ").strip()
#         parts = order.split()
        
#         # Проверка формата ввода (должно быть 3 части)
#         if len(parts) != 3:
#             print("Ошибка: введите заказ в формате 'Покупатель Пицца Количество'. Попробуйте снова.")
#             continue
        
#         buyer, pizza, quantity_str = parts
        
#         # Проверка, что количество - целое положительное число
#         try:
#             quantity = int(quantity_str)
#             if quantity <= 0:
#                 print("Ошибка: количество пицц должно быть положительным числом. Попробуйте снова.")
#                 continue
#         except ValueError:
#             print("Ошибка: количество должно быть целым числом. Попробуйте снова.")
#             continue
        
#         # Проверка, что названия не пустые
#         if not buyer or not pizza:
#             print("Ошибка: имя покупателя и название пиццы не могут быть пустыми. Попробуйте снова.")
#             continue
        
#         # Добавляем заказ в словарь
#         if buyer not in orders:
#             orders[buyer] = {}
        
#         if pizza not in orders[buyer]:
#             orders[buyer][pizza] = 0
        
#         orders[buyer][pizza] += quantity
#         break

# print("ИТОГОВЫЕ ЗАКАЗЫ:")

# # Сортируем покупателей по алфавиту
# for buyer in sorted(orders.keys()):
#     print(f"{buyer}:")
    
#     # Сортируем пиццы по алфавиту для каждого покупателя
#     for pizza in sorted(orders[buyer].keys()):
#         print(f"\t{pizza}: {orders[buyer][pizza]}")





#FIXTO

# Проверка ввода количества заказов.
# Пользователь должен ввести положительное целое число.
# При ошибке ввод повторяется.
while True:
    try:
        n = int(input("Введите кол-во заказов: "))
        if n <= 0:
            print(
                "Ошибка: количество заказов должно быть положительным числом. "
                "Попробуйте снова."
            )
            continue
        break
    except ValueError:
        print("Ошибка: введите целое число. Попробуйте снова.")


# Словарь заказов.
# Структура: покупатель -> пицца -> количество
orders = {}


# Ввод заказов.
# Формат: "Покупатель Пицца Количество"
# Валидация:
# - 3 поля строго
# - количество > 0
# - поля не пустые
for i in range(1, n + 1):
    while True:
        order = input(f"{i} заказ: ").strip()
        parts = order.split()

        if len(parts) != 3:
            print(
                "Ошибка: введите заказ в формате "
                "'Покупатель Пицца Количество'. Попробуйте снова."
            )
            continue

        buyer, pizza, quantity_str = parts

        try:
            quantity = int(quantity_str)
            if quantity <= 0:
                print(
                    "Ошибка: количество пицц должно быть положительным числом. "
                    "Попробуйте снова."
                )
                continue
        except ValueError:
            print("Ошибка: количество должно быть целым числом. Попробуйте снова.")
            continue

        if not buyer or not pizza:
            print(
                "Ошибка: имя покупателя и название пиццы не могут быть пустыми. "
                "Попробуйте снова."
            )
            continue

        if buyer not in orders:
            orders[buyer] = {}

        if pizza not in orders[buyer]:
            orders[buyer][pizza] = 0

        orders[buyer][pizza] += quantity
        break


print("ИТОГОВЫЕ ЗАКАЗЫ:")


# Вывод итоговых заказов.
# Сортировка покупателей и пицц по алфавиту.
for buyer in sorted(orders.keys()):
    print(f"{buyer}:")

    for pizza in sorted(orders[buyer].keys()):
        print(f"\t{pizza}: {orders[buyer][pizza]}")