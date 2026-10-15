/*
FIXME: 
    2. Имя класса Node должно быть CNode
    3. Имя класса Stack должно быть CStack 
    4. Имена полей data, next, top не в PascalCase 
    5. Имена методов не в PascalCase
    6. Имена параметров value, D не в PascalCase и без префикса _ 
    7. Русский текст в cout и в комментариях
    8. Открывающие скобки функций на новых строках
    9. Конструктор Stack() должен быть CStack()
    10. Метод getTop возвращает Node* должен возвращать CNode*
    11. clearStack должен вызываться ClearStack()

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
//class Stack {
//private:
//    Node* top;
//
//public:
//
//    Stack() : top(nullptr) {}
//
//    //  для добавления элемента в стек
//    void push(int value) {
//        Node* newNode = new Node(value); // Создаем новый узел
//        newNode->next = top;             // Новый узел указывает на текущую вершину
//        top = newNode;                   // Обновляем вершину стека
//        cout << "Элемент " << value << " добавлен в стек." << endl;
//    }
//
//    // Метод для удаления элемента из стека
//    void pop() {
//        if (top == nullptr) {
//            cout << "Стек пуст! Невозможно удалить элемент." << endl;
//            return;
//        }
//        Node* temp = top;
//        top = top->next;
//        cout << "Элемент " << temp->data << " удален из стека." << endl;
//        delete temp;
//    }
//
//
//    void print() {
//        if (top == nullptr) {
//            cout << "Стек пуст!" << endl;
//            return;
//        }
//        Node* current = top;
//        cout << "Элементы стека: ";
//        while (current != nullptr) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//
//    Node* getTop() {
//        return top;
//    }
//
//
//    void clearStack() {
//        while (top != nullptr) {
//            Node* temp = top;
//            top = top->next;
//            delete temp;                 // Удаляем узел
//        }
//        cout << "Стек очищен." << endl;
//    }
//
//
//    friend void addElementAndPrintAddress(Stack& stack, int D);
//};
//
//void addElementAndPrintAddress(Stack& stack, int D) {
//    stack.push(D);
//    cout << "Адрес новой вершины стека: " << stack.getTop() << endl;
//}



//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include <iostream>
using namespace std;
#include "CStack.h"


CNode::CNode(int _Value) : Data(_Value), Next(nullptr) {}

CStack::CStack() : _Top(nullptr) {}

void CStack::Push(int _Value) {
    CNode* NewNode = new CNode(_Value);
    NewNode->Next = _Top;
    _Top = NewNode;
    cout << "Element " << _Value << " pushed to stack." << endl;
}

void CStack::Pop() {
    if (_Top == nullptr) {
        cout << "Stack is empty! Cannot pop." << endl;
        return;
    }
    CNode* Temp = _Top;
    _Top = _Top->Next;
    cout << "Element " << Temp->Data << " popped from stack." << endl;
    delete Temp;
}

void CStack::Print() {
    if (_Top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    CNode* Current = _Top;
    cout << "Stack elements: ";
    while (Current != nullptr) {
        cout << Current->Data << " ";
        Current = Current->Next;
    }
    cout << endl;
}

CNode* CStack::GetTop() const {
    return _Top;
}

void CStack::Clear() {
    while (_Top != nullptr) {
        CNode* Temp = _Top;
        _Top = _Top->Next;
        delete Temp;
    }
    cout << "Stack cleared." << endl;
}

void AddElementAndPrintAddress(CStack& _Stack, int _D) {
    _Stack.Push(_D);
    cout << "New top node address: " << _Stack.GetTop() << endl;
}