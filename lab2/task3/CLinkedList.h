// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#pragma once

#include <string>

using namespace std;

// Node class - helper for LinkedList (надстройка)
class CNode {
public:
    int Data;       // Node value
    CNode* Next;    // Pointer to next node

    CNode(int _Value);  // Constructor
};

// LinkedList class - ordered descending linked list
class CLinkedList {
private:
    CNode* _Head;   // Pointer to first node (head)

public:
    CLinkedList();                          // Constructor
    ~CLinkedList();                         // Destructor

    void InsertSorted(int _Value);          // Insert value in descending order
    void Print();                           // Print all list elements
    void ReadFromFile(const string& _FileName);  // Read data from file
    void Clear();                           // Clear entire list

    friend void ReadFromFile(CLinkedList& _List, const string& _FileName);
};