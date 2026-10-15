/*
FIXME :
    1. Имя функции delen не в PascalCase
    2. Параметры должны иметь префикс _
    3. Имена параметров stroka, ind, left не описательные , не в PascalCase
    4. Русский текст в cout
    5. Открывающая скобка на новой строке
*/



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



// FIXTO: 

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include "Delen.h"
#include "Recnum.h"
#include <iostream>

int Delen(const std::string& _String, int& _Index, int _LeftValue) {
    // End of string - return current value
    if (_Index >= _String.length()) {
        return _LeftValue;
    }

    char Operator = _String[_Index];

    // Only handle '*' and '/' operations
    if (Operator != '*' && Operator != '/') {
        return _LeftValue;
    }

    ++_Index; // Move past the operator

    // Parse the right operand (can be multi-digit)
    int RightValue = Recnum(_String, _Index);

    if (Operator == '*') {
        return Delen(_String, _Index, _LeftValue * RightValue);
    }

    if (Operator == '/') {
        if (RightValue == 0) {
            std::cout << "Error: division by zero!" << std::endl;
            exit(1);
        }
        return Delen(_String, _Index, _LeftValue / RightValue);
    }

    return _LeftValue;
}