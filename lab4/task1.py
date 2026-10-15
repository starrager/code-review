# FIXME: Нет аннотаций типов в методах, есть длинные строки,
#        защищённые поля без префикса _
# class Child:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age
#         self.is_calm = True
#         self.is_hungry = True

#     def info(self):
#         calm_status = "спокоен" if self.is_calm else "не спокоен"
#         hungry_status = "голоден" if self.is_hungry else "сыт"
#         return "Ребёнок " + self.name + ", возраст: " + str(self.age) + ", состояние: " + calm_status + ", " + hungry_status

# FIXTO:
# Поля защищены (_), доступ снаружи только через свойство и методы.
class Child:
    def __init__(self, name: str, age: int) -> None:
        self._name = name
        self._age = age
        self._is_calm = True
        self._is_hungry = True

    @property
    def name(self) -> str:
        return self._name

    def calm(self) -> None:
        self._is_calm = True

    def feed(self) -> None:
        self._is_hungry = False

    def info(self) -> str:
        calm_status = "спокоен" if self._is_calm else "не спокоен"
        hungry_status = "голоден" if self._is_hungry else "сыт"
        return (
            "Ребёнок " + self._name + ", возраст: " + str(self._age)
            + ", состояние: " + calm_status + ", " + hungry_status
        )


# FIXME: Нет аннотаций типов в методах, есть длинные строки,
#        защищённые поля без префикса _, обращение к защищённым
#        полям Child (_is_calm, _name) извне класса
# class Parent:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age
#         self.children = []

#     def add_child(self, child):
#         self.children.append(child)

#     def info(self):
#         return "Родитель " + self.name + ", возраст: " + str(self.age) + ", количество детей: " + str(len(self.children))

#     def calm_child(self, child_index):
#         if 0 <= child_index < len(self.children):
#             self.children[child_index].is_calm = True
#             print("Родитель " + self.name + " успокоил ребёнка " + self.children[child_index].name)

#     def feed_child(self, child_index):
#         if 0 <= child_index < len(self.children):
#             self.children[child_index].is_hungry = False
#             print("Родитель " + self.name + " покормил ребёнка " + self.children[child_index].name)


# FIXTO:
class Parent:
    def __init__(self, name: str, age: int) -> None:
        self._name = name
        self._age = age
        self._children: list[Child] = []

    @property
    def name(self) -> str:
        return self._name

    @property
    def children(self) -> list[Child]:
        return self._children

    def add_child(self, child: Child) -> None:
        self._children.append(child)

    def info(self) -> str:
        return (
            "Родитель " + self._name + ", возраст: " + str(self._age)
            + ", количество детей: " + str(len(self._children))
        )

    def calm_child(self, child_index: int) -> None:
        if 0 <= child_index < len(self._children):
            child = self._children[child_index]
            child.calm()
            print(
                "Родитель " + self._name
                + " успокоил ребёнка " + child.name
            )

    def feed_child(self, child_index: int) -> None:
        if 0 <= child_index < len(self._children):
            child = self._children[child_index]
            child.feed()
            print(
                "Родитель " + self._name
                + " покормил ребёнка " + child.name
            )


# FIXME: Есть длинные строки, нет функции main, получается длинная
#        функция, однобуквенные имена переменных (n, k)

# parents = []

# n = int(input("Введите количество родителей: "))

# for i in range(n):
#     print("\nРодитель " + str(i + 1) + ":")
#     parent_name = input("Введите имя родителя: ")
#     parent_age = int(input("Введите возраст родителя: "))

#     parent = Parent(parent_name, parent_age)

#     num_children = int(input("Введите количество детей у этого родителя: "))

#     for j in range(num_children):
#         print("  Ребёнок " + str(j + 1) + ":")
#         child_name = input("  Введите имя ребёнка: ")
#         child_age = int(input("  Введите возраст ребёнка: "))

#         child = Child(child_name, child_age)
#         parent.add_child(child)

#     parents.append(parent)

# while True:
#     print("\nМеню:")
#     print("1) Сообщить информацию о родителе с номером k")
#     print("2) Сообщить информацию о всех детях для заданного родителя k")
#     print("3) Выполнить действие с ребенком")
#     print("4) Выход")

#     choice = int(input("Выберите пункт меню: "))

#     if choice == 1:
#         k = int(input("Введите номер родителя: "))
#         if 1 <= k <= len(parents):
#             print(parents[k - 1].info())
#         else:
#             print("Неверный номер родителя")

#     elif choice == 2:
#         k = int(input("Введите номер родителя: "))
#         if 1 <= k <= len(parents):
#             parent = parents[k - 1]
#             print("\nДети родителя " + parent.name + ":")
#             if parent.children:
#                 for i, child in enumerate(parent.children):
#                     print("  " + str(i + 1) + ") " + child.info())
#             else:
#                 print("  Нет детей")
#         else:
#             print("Неверный номер родителя")

#     elif choice == 3:
#         k = int(input("Введите номер родителя: "))
#         if 1 <= k <= len(parents):
#             parent = parents[k - 1]
#             if parent.children:
#                 child_num = int(input("Введите номер ребёнка (1-" + str(len(parent.children)) + "): "))
#                 if 1 <= child_num <= len(parent.children):
#                     print("\nДействия:")
#                     print("1) Успокоить ребёнка")
#                     print("2) Покормить ребёнка")
#                     action = int(input("Выберите действие: "))

#                     if action == 1:
#                         parent.calm_child(child_num - 1)
#                     elif action == 2:
#                         parent.feed_child(child_num - 1)
#                     else:
#                         print("Неверное действие")
#                 else:
#                     print("Неверный номер ребёнка")
#             else:
#                 print("У этого родителя нет детей")
#         else:
#             print("Неверный номер родителя")

#     elif choice == 4:
#         print("Выход из программы")
#         break

#     else:
#         print("Неверный пункт меню")

# FIXTO:
def input_children() -> list[Child]:
    children = []
    num_children = int(input("Введите количество детей у этого родителя: "))
    for j in range(num_children):
        print("  Ребёнок " + str(j + 1) + ":")
        child_name = input("  Введите имя ребёнка: ")
        child_age = int(input("  Введите возраст ребёнка: "))
        children.append(Child(child_name, child_age))
    return children


def input_parents() -> list[Parent]:
    parents = []
    parents_count = int(input("Введите количество родителей: "))
    for i in range(parents_count):
        print("\nРодитель " + str(i + 1) + ":")
        parent_name = input("Введите имя родителя: ")
        parent_age = int(input("Введите возраст родителя: "))
        parent = Parent(parent_name, parent_age)
        for child in input_children():
            parent.add_child(child)
        parents.append(parent)
    return parents


def print_parent_info(parents: list[Parent]) -> None:
    parent_number = int(input("Введите номер родителя: "))
    if 1 <= parent_number <= len(parents):
        print(parents[parent_number - 1].info())
    else:
        print("Неверный номер родителя")


def print_children_info(parents: list[Parent]) -> None:
    parent_number = int(input("Введите номер родителя: "))
    if 1 <= parent_number <= len(parents):
        parent = parents[parent_number - 1]
        print("\nДети родителя " + parent.name + ":")
        if parent.children:
            for i, child in enumerate(parent.children):
                print("  " + str(i + 1) + ") " + child.info())
        else:
            print("  Нет детей")
    else:
        print("Неверный номер родителя")


def perform_action(parents: list[Parent]) -> None:
    parent_number = int(input("Введите номер родителя: "))
    if 1 <= parent_number <= len(parents):
        parent = parents[parent_number - 1]
        if not parent.children:
            print("У этого родителя нет детей")
            return
        child_num = int(
            input(
                "Введите номер ребёнка (1-"
                + str(len(parent.children)) + "): "
            )
        )
        if 1 <= child_num <= len(parent.children):
            print("\nДействия:")
            print("1) Успокоить ребёнка")
            print("2) Покормить ребёнка")
            action = int(input("Выберите действие: "))
            if action == 1:
                parent.calm_child(child_num - 1)
            elif action == 2:
                parent.feed_child(child_num - 1)
            else:
                print("Неверное действие")
        else:
            print("Неверный номер ребёнка")
    else:
        print("Неверный номер родителя")


def print_menu() -> None:
    print("\nМеню:")
    print("1) Сообщить информацию о родителе с номером k")
    print("2) Сообщить информацию о всех детях для заданного родителя k")
    print("3) Выполнить действие с ребенком")
    print("4) Выход")


def main() -> None:
    parents = input_parents()

    while True:
        print_menu()
        choice = int(input("Выберите пункт меню: "))

        if choice == 1:
            print_parent_info(parents)
        elif choice == 2:
            print_children_info(parents)
        elif choice == 3:
            perform_action(parents)
        elif choice == 4:
            print("Выход из программы")
            break
        else:
            print("Неверный пункт меню")


if __name__ == '__main__':
    main()
