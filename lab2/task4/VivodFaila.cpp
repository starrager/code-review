/*
FIXME:
	1. Отсутствует copyright в первой строке
	2. Имя функции VivodSoderzhimogoFaila должно быть ShowFileContent (английский)
	3. Имя параметра ImyaFaila не в PascalCase и без префикса _ 
	4. Переменная Stroka написана транслитом (Line - английский)
	5. Русский текст в cout

*/



//void VivodSoderzhimogoFaila(const string& ImyaFaila) {
//    ifstream file(ImyaFaila);
//    if (!file.is_open()) {
//        cout << "Ошибка при открытии файла для чтения!" << endl;
//        return;
//    }
//
//    cout << "\n=== Содержимое файла ===" << endl;
//    string Stroka;
//    while (getline(file, Stroka)) {
//        cout << Stroka << endl;
//    }
//    file.close();
//}


//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#include <fstream>
#include <iostream>
#include "VivodFaila.h"
using namespace std;

void ShowFileContent(const string& _FileName) {
    ifstream File(_FileName.c_str());
    if (!File.is_open()) {
        cout << "Error: cannot open file for reading!" << endl;
        return;
    }

    cout << "\n=== File contents ===" << endl;
    string Line;
    while (getline(File, Line)) {
        cout << Line << endl;
    }
    File.close();
}