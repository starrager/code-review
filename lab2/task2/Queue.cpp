/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. Отсутствует #include "CQueue.h"
    3. Имя класса Queue должно быть CQueue
    4. Имя вложенной структуры Node  должно быть CNode
    5. Имена полей P1, P2 не в PascalCase , не описательные (_Head, _Tail)
    6. Имена полей data, next не в PascalCase 
    7. Имена методов не в PascalCase
    8. Параметры без префикса _
    9. Русский текст в cout и комментариях 
    12. Метод EvenHead() должен использовать Pop() и проверять IsEmpty()
    13. Деструктор должен использовать Pop()
    14. Нет проверки на nullptr в getP1data и getP2data
*/



//class Queue {
//private:
//    struct Node {
//        int data;
//        Node* next;
//    };
//
//    Node* P1;
//    Node* P2;
//
//public:
//    Queue() : P1(nullptr), P2(nullptr) {}
//
//    void push(int num) { // Добавление элемента в очередь
//        Node* newNode = new Node;
//        newNode->data = num;
//        newNode->next = nullptr;
//        if (!P2) {
//            P1 = P2 = newNode;
//        }
//        else {
//            P2->next = newNode;
//            P2 = newNode;
//        }
//        newNode->next = nullptr;
//    }
//    void show() { // Вывод элементов
//        Node* temp = P1;
//        if (!temp) {
//            cout << "Очередь пустая" << endl;
//            return;
//        }
//        while (temp) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//    bool pop(int& num) {  // Извлечение элемента из очереди
//        if (!P1) return false; // Очередь пуста
//
//        Node* temp = P1;
//        num = P1->data;
//        P1 = P1->next;
//        if (!P1) P2 = nullptr; // Если очередь стала пустой
//
//        delete temp;
//        return true;
//    }
//
//    Node* getP1() const {
//        return P1;
//    }
//    void getP1data() const {
//        int num1 = P1->data;
//        cout << num1;
//    }
//
//    void getP2data() const {
//        int num1 = P2->data;
//        cout << num1;
//    }
//
//    Node* getP2() const {
//        return P2;
//    }
//
//    void EvenHead() { // Извлечение элементов, пока не встретится четное значение
//        int num;
//        while (!(P1 == nullptr) && (P1->data % 2 != 0)) {
//            pop(num);
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//
//    ~Queue() {
//        int del;
//        while (pop(del));
//    }
//};


//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
using namespace std;
#include "Queue.h"

CQueue::CNode::CNode(int _Value) : Data(_Value), Next(nullptr) {}
CQueue::CQueue() : _Head(nullptr), _Tail(nullptr) {}
CQueue::~CQueue() {
    int Dummy;
    while (Pop(Dummy));
}

// Push: adds new element to the end (tail) of the queue
void CQueue::Push(int _Value) {
    CNode* NewNode = new CNode(_Value);
    if (_Tail == nullptr) {
        _Head = _Tail = NewNode;
    }
    else {
        _Tail->Next = NewNode;
        _Tail = NewNode;
    }
}

// Show: prints all queue elements from head to tail
void CQueue::Show() {
    if (_Head == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }
    CNode* Current = _Head;
    cout << "Queue elements: ";
    while (Current != nullptr) {
        cout << Current->Data << " ";
        Current = Current->Next;
    }
    cout << endl;
}

// Pop: removes and returns the value of the front (head) element
// Returns true if element was removed, false if queue is empty
bool CQueue::Pop(int& _Value) {
    if (_Head == nullptr) {
        return false;  
    }
    CNode* Temp = _Head;
    _Value = _Head->Data;
    _Head = _Head->Next;
    if (_Head == nullptr) {
        _Tail = nullptr;
    }
    delete Temp;
    return true;
}

// EvenHead: extracts and outputs elements while head value is odd
// Stops when head becomes even or queue becomes empty
void CQueue::EvenHead() {
    int Value;
    while (!IsEmpty() && (_Head->Data % 2 != 0)) {
        Pop(Value);
        cout << Value << " ";
    }
    cout << endl;
}

// GetHead: returns pointer to the head node (P1)
CQueue::CNode* CQueue::GetHead() const {
    return _Head;
}

// GetTail: returns pointer to the tail node (P2)
CQueue::CNode* CQueue::GetTail() const {
    return _Tail;
}

// GetHeadValue: returns value of the head element
// Returns 0 if queue is empty (caller should check IsEmpty first)
int CQueue::GetHeadValue() const {
    if (_Head == nullptr) {
        return 0;
    }
    return _Head->Data;
}

// GetTailValue: returns value of the tail element
// Returns 0 if queue is empty (caller should check IsEmpty first)
int CQueue::GetTailValue() const {
    if (_Tail == nullptr) {
        return 0;
    }
    return _Tail->Data;
}

// IsEmpty: checks whether the queue is empty
bool CQueue::IsEmpty() const {
    return _Head == nullptr;
}