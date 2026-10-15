/*
FIXME:
	1. Отсутствует copyright в первой строке
	3. Имя класса Node должно быть CNode
	4. Имя класса LinkedList должно быть CLinkedList
	5. Имена полей data, next, head не в PascalCase 
	6. Имена методов не в PascalCase
	7. Параметры без префикса _
	8. Русский текст в комментариях

*/


//class Node {
//public:
//    int data;
//    Node* next;
//
//
//    Node(int value) : data(value), next(nullptr) {}
//};
//
//class LinkedList {
//private:
//    Node* head;
//
//public:
//
//    LinkedList() : head(nullptr) {}
//
//
//    void insertSorted(int value) {
//        Node* newNode = new Node(value);
//        if (head == nullptr || head->data < value) {
//            newNode->next = head;
//            head = newNode;
//        }
//        else {
//            Node* current = head;
//            while (current->next != nullptr && current->next->data > value) {
//                current = current->next;
//            }
//            newNode->next = current->next;
//            current->next = newNode;
//        }
//    }
//
//
//    void print() {
//        Node* current = head;
//        while (current != nullptr) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//
//    void readFromFile(const std::string& filename) {
//        ifstream file(filename);   // Открываем файл для чтения
//        if (!file.is_open()) {          // Проверяем, удалось ли открыть файл
//            cerr << "Ошибка открытия файла!" << endl;
//            return;
//        }
//
//        int N;
//        file >> N;                      // Читаем количество элементов
//
//        int value;
//        for (int i = 0; i < N; ++i) {   // Читаем элементы и добавляем их в список
//            file >> value;
//            insertSorted(value);         // Вставляем элемент с сохранением упорядоченности
//        }
//
//        file.close();                   // Закрываем файл
//    }
//
//
//    friend void readFromFile(LinkedList& list, const string& filename);
//};


//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#include <fstream>
#include <iostream>
using namespace std;
#include "CLinkedList.h"

CNode::CNode(int _Value) : Data(_Value), Next(nullptr) {}
CLinkedList::CLinkedList() : _Head(nullptr) {}
CLinkedList::~CLinkedList() {
    Clear();
}

// InsertSorted - inserts value in descending order
void CLinkedList::InsertSorted(int _Value) {
    CNode* NewNode = new CNode(_Value);

    if (_Head == nullptr || _Head->Data < _Value) {
        NewNode->Next = _Head;
        _Head = NewNode;
    }
    else {
        CNode* Current = _Head;
        while (Current->Next != nullptr && Current->Next->Data > _Value) {
            Current = Current->Next;
        }
        NewNode->Next = Current->Next;
        Current->Next = NewNode;
    }
}

// Print - outputs all list elements
void CLinkedList::Print() {
    if (_Head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    CNode* Current = _Head;
    cout << "Sorted list (descending): ";
    while (Current != nullptr) {
        cout << Current->Data << " ";
        Current = Current->Next;
    }
    cout << endl;
}

// ReadFromFile - reads N and N integers from file
void CLinkedList::ReadFromFile(const string& _FileName) {
    ifstream File(_FileName.c_str());
    if (!File.is_open()) {
        cerr << "Error: cannot open file " << _FileName << endl;
        return;
    }

    int ElementCount;
    File >> ElementCount;

    int Value;
    for (int ElementIdx = 0; ElementIdx < ElementCount; ++ElementIdx) {
        File >> Value;
        InsertSorted(Value);
    }

    File.close();
}

// Clear - removes all nodes from list
void CLinkedList::Clear() {
    while (_Head != nullptr) {
        CNode* Temp = _Head;
        _Head = _Head->Next;
        delete Temp;
    }
}

// Friend function implementation
void ReadFromFile(CLinkedList& _List, const string& _FileName) {
    _List.ReadFromFile(_FileName);
}