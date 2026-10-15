/*
FIXME для исходного main:
    1. Отсутствует copyright
    2. setlocale(LC_ALL, "RU") - русский язык
    3. Русский текст в cout
    4. Имена переменных s, ind, res не в PascalCase , не описательные
    5. Нет комментариев
    6. Открывающая скобка main на новой строке
    7. Функции в одном файле
*/

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//int primer(const string& stroka, int& ind, int left) {
//    if (ind >= stroka.length()) return left;
//
//    char op = stroka[ind];
//    if (op != '+' && op != '-') return left;
//
//    ind++;
//    int right = delen(stroka, ind, recnum(stroka, ind));
//
//    if (op == '+') return primer(stroka, ind, left + right);
//    if (op == '-') return primer(stroka, ind, left - right);
//
//    return left;
//}
//
//int recnum(const string& stroka, int& ind) {
//    if (ind >= stroka.length() || !isdigit(stroka[ind]))
//        return 0;
//
//    int num = stroka[ind++] - '0'; // Преобразуем символ в число
//    int next = recnum(stroka, ind); // Читаем следующие цифры
//
//    return next == 0 ? num : num * 10 + next; // Собираем многозначное число
//}
//
//int delen(const string& stroka, int& ind, int left) {
//    if (ind >= stroka.length()) return left;
//
//    char op = stroka[ind];
//    if (op != '*' && op != '/') return left;
//
//    ind++;
//    int right = recnum(stroka, ind);
//
//    if (op == '*') return delen(stroka, ind, left * right);
//    if (op == '/') {
//        if (right == 0) {
//            cout << "Ошибка: деление на 0!" << endl;
//            exit(1);
//        }
//        return delen(stroka, ind, left / right);
//    }
//    return left;
//}
//
//
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    string s;
//    cout << "Введите выражение:" << endl;
//    cin >> s;
//
//    int ind = 0;
//    int res = primer(s, ind, delen(s, ind, recnum(s, ind)));
//    cout << "Результат: " << res << endl;
//
//    return 0;
//}


//FIXTO : 

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include <iostream>
#include <string>

#include "Primer.h"
#include "Delen.h"
#include "Recnum.h"

int main() {
    std::string Expression;   // Input expression string
    std::cout << "Enter expression: " << std::endl;
    std::cin >> Expression;

    int Index = 0;  // Current parsing position

    int Result = Primer(Expression, Index, Delen(Expression, Index, Recnum(Expression, Index)));

    std::cout << "Result: " << Result << std::endl;

    return 0;
}