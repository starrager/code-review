// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#pragma once

#include <iostream>

class CNode {
public:
    int Data;       
    CNode* Next;  

    CNode(int _Value); 
};


class CStack {
private:
    CNode* _Top;    

public:
    CStack();                           
    void Push(int _Value);              
    void Pop();                         
    void Print();                       
    CNode* GetTop() const;              
    void Clear();                       

    friend void AddElementAndPrintAddress(CStack& _Stack, int _D);
};