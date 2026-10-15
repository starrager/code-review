/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. Имя структуры Uzel должно быть с префиксом (SUzel)
    3. Имя класса Spisok должно быть CSpisok
    4. Имена полей не в PascalCase
    5. Имена методов не в PascalCase
    6. Имена параметров не в PascalCase и без префикса _
    7. Переменные не в PascalCase

*/



//// Структура узла двусвязного списка
//struct Uzel {
//    int Dannye;         // Данные узла
//    Uzel* Predydushiy;  // Указатель на предыдущий узел
//    Uzel* Sleduyushiy;  // Указатель на следующий узел
//};
//
//// Класс для работы с двусвязным списком
//class Spisok {
//private:
//    Uzel* Perviy; // Указатель на первый узел
//
//public:
//    // Инициализация списка
//    void Inicializacia() {
//        Perviy = nullptr;
//    }
//
//    // Добавление элемента в конец списка
//    void DobavitElement(int Znachenie) {
//        Uzel* Novyj = new Uzel;
//        Novyj->Dannye = Znachenie;
//        Novyj->Predydushiy = nullptr;
//        Novyj->Sleduyushiy = nullptr;
//
//        if (Perviy == nullptr) {
//            Perviy = Novyj;
//        }
//        else {
//            Uzel* Tekushiy = Perviy;
//            while (Tekushiy->Sleduyushiy != nullptr) {
//                Tekushiy = Tekushiy->Sleduyushiy;
//            }
//            Tekushiy->Sleduyushiy = Novyj;
//            Novyj->Predydushiy = Tekushiy;
//        }
//    }
//
//    // Удаление указанного узла
//    void UdalitElement(Uzel* UzelDlyaUdaleniya) {
//        if (UzelDlyaUdaleniya == nullptr) return;
//
//        Uzel* Pred = UzelDlyaUdaleniya->Predydushiy;
//        Uzel* Sled = UzelDlyaUdaleniya->Sleduyushiy;
//
//        if (Pred != nullptr) {
//            Pred->Sleduyushiy = Sled;
//        }
//        else {
//            Perviy = Sled;
//        }
//
//        if (Sled != nullptr) {
//            Sled->Predydushiy = Pred;
//        }
//
//        delete UzelDlyaUdaleniya;
//    }
//
//    // Вывод списка на экран
//    void Pechat() const {
//        Uzel* Tekushiy = Perviy;
//        cout << "Список: ";
//        while (Tekushiy != nullptr) {
//            cout << Tekushiy->Dannye << " ";
//            Tekushiy = Tekushiy->Sleduyushiy;
//        }
//        cout << endl;
//    }
//
//    // Запись в файл в обратном порядке и удаление элементов
//    void ZapisatVFailIOchistit(const string& ImyaFaila) {
//        ofstream file(ImyaFaila);
//        if (!file.is_open()) {
//            cout << "Ошибка открытия файла!" << endl;
//            return;
//        }
//
//        bool PerviyElement = true;
//        Uzel* Tekushiy = Perviy;
//
//        // Находим последний элемент
//        while (Tekushiy != nullptr && Tekushiy->Sleduyushiy != nullptr) {
//            Tekushiy = Tekushiy->Sleduyushiy;
//        }
//
//        // Записываем и удаляем элементы с конца
//        while (Tekushiy != nullptr) {
//            if (PerviyElement) {
//                file << Tekushiy->Dannye;
//                PerviyElement = false;
//            }
//            else {
//                file << " " << Tekushiy->Dannye;
//            }
//
//            Uzel* Predydushiy = Tekushiy->Predydushiy;
//            UdalitElement(Tekushiy);
//            Tekushiy = Predydushiy;
//        }
//
//        file.close();
//        cout << "Данные записаны в файл и список очищен." << endl;
//    }
//
//    // Очистка всего списка
//    void Ochistka() {
//        Uzel* Tekushiy = Perviy;
//        while (Tekushiy != nullptr) {
//            Uzel* Sleduyushiy = Tekushiy->Sleduyushiy;
//            delete Tekushiy;
//            Tekushiy = Sleduyushiy;
//        }
//        Perviy = nullptr;
//    }
//};



//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.


#include <fstream>
#include <iostream>
#include "UzelSpisok.h"
using namespace std;


SUzel::SUzel(int _Value) : Data(_Value), Prev(nullptr), Next(nullptr) {}
CSpisok::CSpisok() : _Head(nullptr) {}
CSpisok::~CSpisok() {
    Clear();
}

// Initialize empty list
void CSpisok::Init() {
    Clear();
    _Head = nullptr;
}

// Add element to the end of the list
void CSpisok::Add(int _Value) {
    SUzel* NewNode = new SUzel(_Value);

    if (_Head == nullptr) {
        _Head = NewNode;
    }
    else {
        SUzel* Current = _Head;
        while (Current->Next != nullptr) {
            Current = Current->Next;
        }
        Current->Next = NewNode;
        NewNode->Prev = Current;
    }
}

// Remove specified node
void CSpisok::Remove(SUzel* _Node) {
    if (_Node == nullptr) return;

    SUzel* PrevNode = _Node->Prev;
    SUzel* NextNode = _Node->Next;

    if (PrevNode != nullptr) {
        PrevNode->Next = NextNode;
    }
    else {
        _Head = NextNode;
    }

    if (NextNode != nullptr) {
        NextNode->Prev = PrevNode;
    }

    delete _Node;
}

// Print list to console
void CSpisok::Print() const {
    if (_Head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    SUzel* Current = _Head;
    cout << "List: ";
    while (Current != nullptr) {
        cout << Current->Data << " ";
        Current = Current->Next;
    }
    cout << endl;
}

// Write list in reverse order to file and delete nodes
void CSpisok::WriteToFileAndClear(const string& _FileName) {
    ofstream File(_FileName.c_str());
    if (!File.is_open()) {
        cout << "Error: cannot open file!" << endl;
        return;
    }

    // Find the last node (tail)
    SUzel* Current = _Head;
    while (Current != nullptr && Current->Next != nullptr) {
        Current = Current->Next;
    }

    // Write from tail to head and delete nodes
    bool FirstElement = true;
    while (Current != nullptr) {
        if (FirstElement) {
            File << Current->Data;
            FirstElement = false;
        }
        else {
            File << " " << Current->Data;
        }

        SUzel* PrevNode = Current->Prev;
        Remove(Current);
        Current = PrevNode;
    }

    File.close();
    cout << "Data written to file and list cleared." << endl;
}

// Clear entire list
void CSpisok::Clear() {
    SUzel* Current = _Head;
    while (Current != nullptr) {
        SUzel* NextNode = Current->Next;
        delete Current;
        Current = NextNode;
    }
    _Head = nullptr;
}