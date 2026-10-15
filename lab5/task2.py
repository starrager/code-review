# FIXME: 1. Строки длиннее 80 символов (строки 4, 12, 20, 28, 36, 44, 52, 60).
# FIXME: 2. Нет docstring (описания модуля и функций).
# FIXME: 3. Неинформативные имена (n, orders, i как номер заказа).
# FIXME: 4. Код на уровне модуля: нет функций, main и
#        if __name__ == '__main__', все переменные глобальные.
# FIXME: 5. Нет аннотаций типов.


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


# FIXTO:
"""Учёт заказов пиццы.

Программа читает заказы в формате «Покупатель Пицца Количество»,
суммирует одинаковые позиции и выводит итог по каждому покупателю.
"""


def input_orders_count() -> int:
    """Запрашивает количество заказов.

    Ввод повторяется, пока не будет введено положительное целое число.

    Returns:
        Количество заказов.
    """
    while True:
        try:
            orders_count = int(input("Введите кол-во заказов: "))
            if orders_count <= 0:
                print(
                    "Ошибка: количество заказов должно быть положительным "
                    "числом. Попробуйте снова."
                )
                continue
            return orders_count
        except ValueError:
            print("Ошибка: введите целое число. Попробуйте снова.")


def input_order(order_number: int) -> tuple[str, str, int]:
    """Запрашивает один заказ и проверяет формат ввода.

    Формат: «Покупатель Пицца Количество», ровно три поля,
    количество - целое число больше нуля.

    Args:
        order_number: порядковый номер заказа (для приглашения к вводу).

    Returns:
        Кортеж (покупатель, пицца, количество).
    """
    while True:
        parts = input(f"{order_number} заказ: ").strip().split()

        if len(parts) != 3:
            print(
                "Ошибка: введите заказ в формате "
                "'Покупатель Пицца Количество'. Попробуйте снова."
            )
            continue

        buyer, pizza, quantity_str = parts

        try:
            quantity = int(quantity_str)
        except ValueError:
            print(
                "Ошибка: количество должно быть целым числом. "
                "Попробуйте снова."
            )
            continue

        if quantity <= 0:
            print(
                "Ошибка: количество пицц должно быть положительным "
                "числом. Попробуйте снова."
            )
            continue

        return buyer, pizza, quantity


def add_order(
    orders_by_buyer: dict[str, dict[str, int]],
    buyer: str,
    pizza: str,
    quantity: int,
) -> None:
    """Добавляет заказ в словарь, суммируя одинаковые пиццы.

    Args:
        orders_by_buyer: словарь покупатель -> пицца -> количество.
        buyer: имя покупателя.
        pizza: название пиццы.
        quantity: количество пицц.
    """
    buyer_orders = orders_by_buyer.setdefault(buyer, {})
    buyer_orders[pizza] = buyer_orders.get(pizza, 0) + quantity


def print_orders(orders_by_buyer: dict[str, dict[str, int]]) -> None:
    """Выводит итоговые заказы, отсортированные по алфавиту.

    Args:
        orders_by_buyer: словарь покупатель -> пицца -> количество.
    """
    print("ИТОГОВЫЕ ЗАКАЗЫ:")

    for buyer in sorted(orders_by_buyer):
        print(f"{buyer}:")

        for pizza in sorted(orders_by_buyer[buyer]):
            print(f"\t{pizza}: {orders_by_buyer[buyer][pizza]}")


def main() -> None:
    """Запускает программу: ввод заказов и вывод итогов."""
    orders_count = input_orders_count()
    orders_by_buyer: dict[str, dict[str, int]] = {}

    for i in range(1, orders_count + 1):
        buyer, pizza, quantity = input_order(i)
        add_order(orders_by_buyer, buyer, pizza, quantity)

    print_orders(orders_by_buyer)


if __name__ == '__main__':
    main()
