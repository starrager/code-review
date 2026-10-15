// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#pragma once

#include <fstream>
#include <string>

// Binary tree node structure
struct SNode {
    int Value;          // For numbers: 0-9, for operations: -1 to -6
    SNode* Left;        // Pointer to left subtree
    SNode* Right;       // Pointer to right subtree

    SNode(int _Value);  // Constructor
};

// Checks if the value is an operation
bool IsOperation(int _Value);

// Performs an operation on two operands
int ApplyOperation(int _Op, int _Left, int _Right);

// Builds a tree from a prefix expression, reading tokens from a file
SNode* BuildTree(std::ifstream& _File);

// Optimizes the tree: computes and collapses numeric subtrees
SNode* OptimizeTree(SNode* _Root);

// Prints the tree to the console (for debugging)
void PrintTree(SNode* _Root);

// Frees the memory allocated for the tree
void DeleteTree(SNode* _Root);