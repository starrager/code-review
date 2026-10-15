/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. Имя функции VvodChisla должно быть InputNumber (PascalCase, английский)
    3. Имена переменных не в PascalCase: Vvod, Korrektno, Znak, Start, Chislo
    4. Русский текст в cout
*/


//int VvodChisla() {
//    string Vvod;
//    while (true) {
//        cout << "Введите число (или '-1' для завершения): ";
//        cin >> Vvod;
//
//        if (Vvod == "-1") {
//            return -1;
//        }
//
//        bool Korrektno = true;
//        int Znak = 1;
//        size_t Start = 0;
//
//        if (Vvod.empty()) {
//            Korrektno = false;
//        }
//        else if (Vvod[0] == '-') {
//            Znak = -1;
//            Start = 1;
//            if (Vvod.size() == 1) Korrektno = false;
//        }
//
//        for (size_t i = Start; i < Vvod.size(); ++i) {
//            if (!isdigit(Vvod[i])) Korrektno = false;
//        }
//
//        if (Korrektno) {
//            int Chislo = 0;
//            for (size_t i = Start; i < Vvod.size(); ++i) {
//                Chislo = Chislo * 10 + (Vvod[i] - '0');
//            }
//            return Chislo * Znak;
//        }
//        else {
//            cout << "Некорректный ввод! Используйте цифры и знак '-' в начале." << endl;
//        }
//    }
//}
//



//FIXTO:
// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#include <iostream>
#include <string>
#include <cctype>
#include "VvodChisla.h"
using namespace std;

int InputNumber() {
    string Input;
    while (true) {
        cout << "Enter number (-1 to finish): ";
        cin >> Input;

        if (Input == "-1") {
            return -1;
        }

        bool Valid = true;
        int Sign = 1;
        size_t Start = 0;

        if (Input.empty()) {
            Valid = false;
        }
        else if (Input[0] == '-') {
            Sign = -1;
            Start = 1;
            if (Input.size() == 1) Valid = false;
        }

        for (size_t i = Start; i < Input.size(); ++i) {
            if (!isdigit(Input[i])) Valid = false;
        }

        if (Valid) {
            int Number = 0;
            for (size_t i = Start; i < Input.size(); ++i) {
                Number = Number * 10 + (Input[i] - '0');
            }
            return Number * Sign;
        }
        else {
            cout << "Invalid input! Use digits and optional '-' sign." << endl;
        }
    }
}