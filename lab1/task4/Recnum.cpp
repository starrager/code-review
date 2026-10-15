/*
FIXME :
    1. Имя функции recnum должно быть в PascalCase
    2. Параметры должны иметь префикс _ 
    3. Имена параметров stroka, ind не описательные , не в PascalCase
    4. Русские комментарии
    5. Открывающая скобка на новой строке
*/


//int recnum(const string& stroka, int& ind) {
//    if (ind >= stroka.length() || !isdigit(stroka[ind]))
//        return 0;
//
//    int num = stroka[ind++] - '0'; // Преобразуем символ в число
//    int next = recnum(stroka, ind); // Читаем следующие цифры
//
//    return next == 0 ? num : num * 10 + next; // Собираем многозначное число
//}



// FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include "Recnum.h"
#include <cctype>


int Recnum(const std::string& _String, int& _Index) {
    // Base case: end of string or not a digit
    if (_Index >= _String.length() || !std::isdigit(_String[_Index])) {
        return 0;
    }

    // Convert current digit character to integer
    int CurrentDigit = _String[_Index] - '0';
    ++_Index;

    // Recursively read remaining digits
    int NextDigits = Recnum(_String, _Index);

    // Build multi-digit number: current digit + next digits * 10
    return (NextDigits == 0) ? CurrentDigit : CurrentDigit * 10 + NextDigits;
}