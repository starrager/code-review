// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#pragma once

#include <string>

using namespace std;

// Doubly linked list node structure
struct SUzel {
    int Data;       
    SUzel* Prev;    
    SUzel* Next;    

    SUzel(int _Value);  
};

// Doubly linked list class
class CSpisok {
private:
    SUzel* _Head;   

public:
    CSpisok();                         
    ~CSpisok();                       

    void Init();                        // Initialize empty list
    void Add(int _Value);               // Add element to the end
    void Remove(SUzel* _Node);          // Remove specified node
    void Print() const;                 // Print list to console
    void WriteToFileAndClear(const string& _FileName);  // Write to file in reverse order and clear
    void Clear();                       // Clear entire list

    friend void WriteToFileAndClear(CSpisok& _List, const string& _FileName);
};