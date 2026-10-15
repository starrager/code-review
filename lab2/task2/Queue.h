// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#pragma once

#include <iostream>

class CQueue {
private:
    struct CNode {
        int Data;       
        CNode* Next;    

        CNode(int _Value);  
    };

    CNode* _Head;   
    CNode* _Tail;   

public:
    CQueue();                           
    ~CQueue();                          

    void Push(int _Value);              // Add element to queue tail
    bool Pop(int& _Value);              // Extract element from queue head
    void Show();                        // Print all queue elements
    void EvenHead();                    // Extract until head value is even
    CNode* GetHead() const;             // Get pointer to queue head (P1)
    CNode* GetTail() const;             // Get pointer to queue tail (P2)
    int GetHeadValue() const;           // Get value of head element
    int GetTailValue() const;           // Get value of tail element
    bool IsEmpty() const;               // Check if queue is empty

    // Friend function for task logic
    friend void ProcessQueue(CQueue& _Queue);
};