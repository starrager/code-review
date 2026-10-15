/*
FIXME для исходной функции:
    1. Имя функции primer не в PascalCase
    2. Параметры должны иметь префикс _
    3. Имена параметров stroka, ind, left не описательные , не в PascalCase
   
*/

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




// FIXTO: 

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include "Primer.h"
#include "Delen.h"
#include "Recnum.h"

int Primer(const std::string& _String, int& _Index, int _LeftValue) {
    // End of string - return current value
    if (_Index >= _String.length()) {
        return _LeftValue;
    }

    char Operator = _String[_Index];

    // Only handle '+' and '-' operations
    if (Operator != '+' && Operator != '-') {
        return _LeftValue;
    }

    ++_Index; // Move past the operator

    // Parse right operand: multiplication/division first, then number
    int RightValue = Delen(_String, _Index, Recnum(_String, _Index));

    if (Operator == '+') {
        return Primer(_String, _Index, _LeftValue + RightValue);
    }

    if (Operator == '-') {
        return Primer(_String, _Index, _LeftValue - RightValue);
    }

    return _LeftValue;
}