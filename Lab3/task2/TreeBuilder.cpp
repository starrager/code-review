/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. Имя структуры Node должно быть SNode 
    3. Имена полей value, left, right  должны быть Value, Left, Right (PascalCase)
    4. Имена методов: isOperation не в PascalCase
    5. Имена параметров без префикса _ (val, op, a, b, file, root)
    6. Параметр file - (_File), root  (_Root)
    7. Переменные не в PascalCase
    8. Русский язык
*/


//// Структура узла дерева
//struct Node {
//    int value;  // Для чисел: 0-9, для операций: -1 до -6
//    Node* left;
//    Node* right;
//
//    Node(int val) : value(val), left(nullptr), right(nullptr) {}
//};
//
//// Функция для проверки, является ли значение операцией
//bool isOperation(int val) {
//    return val >= -6 && val <= -1;
//}
//
//// Функция для выполнения операции
//int applyOperation(int op, int a, int b) {
//    switch (op) {
//    case -1: return a + b;      // сложение
//    case -2: return a - b;      // вычитание
//    case -3: return a * b;      // умножение
//    case -4: return a / b;      // деление нацело
//    case -5: return a % b;      // остаток от деления
//    case -6: return pow(a, b);  // возведение в степень
//    default: return 0;
//    }
//}
//
//// Функция для построения дерева из префиксного выражения
//Node* buildTree(ifstream& file) {
//    string token;
//    file >> token;
//
//    if (token.empty()) return nullptr;
//
//    // Пробуем преобразовать в число
//    int value;
//    bool isNumber = true;
//
//    // Проверяем, является ли токен числом
//    for (char c : token) {
//        if (!isdigit(c)) {
//            isNumber = false;
//            break;
//        }
//    }
//
//    if (isNumber) {
//        // Это операнд (число)
//        value = stoi(token);
//        return new Node(value);
//    }
//    else {
//        // Это операция - преобразуем в соответствующий код
//        if (token == "+") value = -1;
//        else if (token == "-") value = -2;
//        else if (token == "*") value = -3;
//        else if (token == "/") value = -4;
//        else if (token == "%") value = -5;
//        else if (token == "^") value = -6;
//        else return nullptr;
//
//        Node* node = new Node(value);
//        node->left = buildTree(file);
//        node->right = buildTree(file);
//        return node;
//    }
//}
//
//// Функция для вычисления и оптимизации дерева
//Node* optimizeTree(Node* root) {
//    if (!root) return nullptr;
//
//    // Если это лист (число), возвращаем как есть
//    if (!isOperation(root->value)) {
//        return root;
//    }
//
//    // Рекурсивно оптимизируем левое и правое поддеревья
//    root->left = optimizeTree(root->left);
//    root->right = optimizeTree(root->right);
//
//    // Если оба поддерева - числа, вычисляем результат
//    if (root->left && root->right &&
//        !isOperation(root->left->value) &&
//        !isOperation(root->right->value)) {
//
//        int result = applyOperation(root->value, root->left->value, root->right->value);
//
//        // Если результат в диапазоне 0-9, заменяем поддерево на число
//        if (result >= 0 && result <= 9) {
//            delete root->left;
//            delete root->right;
//            root->value = result;
//            root->left = nullptr;
//            root->right = nullptr;
//        }
//    }
//
//    return root;
//}
//
//// Функция для вывода дерева (для отладки)
//void printTree(Node* root) {
//    if (!root) return;
//
//    if (isOperation(root->value)) {
//        string op;
//        switch (root->value) {
//        case -1: op = "+"; break;
//        case -2: op = "-"; break;
//        case -3: op = "*"; break;
//        case -4: op = "/"; break;
//        case -5: op = "%"; break;
//        case -6: op = "^"; break;
//        }
//        cout << "(" << op << " ";
//        printTree(root->left);
//        cout << " ";
//        printTree(root->right);
//        cout << ")";
//    }
//    else {
//        cout << root->value;
//    }
//}
//
//// Функция для освобождения памяти
//void deleteTree(Node* root) {
//    if (!root) return;
//    deleteTree(root->left);
//    deleteTree(root->right);
//    delete root;
//}







//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include "TreeBuilder.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructor SNode
// Purpose: Initializes a tree node with a value.
// Parameters: _Value - numeric value (0-9) or operation code (-1 to -6).
// Returns: Nothing (constructor).
// Complexity: O(1).
SNode::SNode(int _Value) : Value(_Value), Left(nullptr), Right(nullptr) {}

// IsOperation
// Purpose: Checks if the value is an operation code.
// Parameters: _Value - value to check.
// Returns: true if value is between -6 and -1, false otherwise.
// Complexity: O(1).
bool IsOperation(int _Value) {
    return _Value >= -6 && _Value <= -1;
}

// ApplyOperation
// Purpose: Performs an arithmetic operation on two operands.
// Parameters:
//   _Op    - operation code (-1=+, -2=-, -3=*, -4=/, -5=%, -6=^)
//   _Left  - left operand
//   _Right - right operand
// Returns: Result of the operation.
// Complexity: O(1) for basic operations, O(log n) for exponentiation.
int ApplyOperation(int _Op, int _Left, int _Right) {
    switch (_Op) {
    case -1: return _Left + _Right;      // addition
    case -2: return _Left - _Right;      // subtraction
    case -3: return _Left * _Right;      // multiplication
    case -4:                             // integer division
        if (_Right == 0) {
            cerr << "Error: Division by zero!" << endl;
            return 0;
        }
        return _Left / _Right;
    case -5:                             // modulo
        if (_Right == 0) {
            cerr << "Error: Modulo by zero!" << endl;
            return 0;
        }
        return _Left % _Right;
    case -6: return static_cast<int>(pow(_Left, _Right)); // exponentiation
    default: return 0;
    }
}

// BuildTree
// Purpose: Builds a binary tree from a prefix expression read from a file.
// Parameters: _File - input file stream positioned at the expression.
// Returns: Pointer to the root of the constructed tree.
//          Returns nullptr if the expression is empty or invalid.
// Complexity: O(n), where n is the number of tokens.
SNode* BuildTree(ifstream& _File) {
    string Token;
    _File >> Token;

    if (Token.empty()) return nullptr;

    // Check if token is a number
    bool IsNumber = true;
    for (char c : Token) {
        if (!isdigit(c)) {
            IsNumber = false;
            break;
        }
    }

    if (IsNumber) {
        // Operand (number)
        int Value = stoi(Token);
        return new SNode(Value);
    }
    else {
        // Operation - convert to corresponding code
        int Value;
        if (Token == "+") Value = -1;
        else if (Token == "-") Value = -2;
        else if (Token == "*") Value = -3;
        else if (Token == "/") Value = -4;
        else if (Token == "%") Value = -5;
        else if (Token == "^") Value = -6;
        else return nullptr;

        SNode* Node = new SNode(Value);
        Node->Left = BuildTree(_File);
        Node->Right = BuildTree(_File);
        return Node;
    }
}

// OptimizeTree
// Purpose: Optimizes the tree by computing and collapsing numeric subtrees.
// Parameters: _Root - pointer to the root of the tree.
// Returns: Pointer to the optimized tree root.
// Complexity: O(n), where n is the number of nodes.
SNode* OptimizeTree(SNode* _Root) {
    if (!_Root) return nullptr;

    // If leaf (number), return as is
    if (!IsOperation(_Root->Value)) {
        return _Root;
    }

    // Recursively optimize left and right subtrees
    _Root->Left = OptimizeTree(_Root->Left);
    _Root->Right = OptimizeTree(_Root->Right);

    // If both subtrees are numbers, compute the result
    if (_Root->Left && _Root->Right &&
        !IsOperation(_Root->Left->Value) &&
        !IsOperation(_Root->Right->Value)) {

        int Result = ApplyOperation(_Root->Value, _Root->Left->Value, _Root->Right->Value);

        // If result is in range 0-9, replace subtree with a number
        if (Result >= 0 && Result <= 9) {
            delete _Root->Left;
            delete _Root->Right;
            _Root->Value = Result;
            _Root->Left = nullptr;
            _Root->Right = nullptr;
        }
    }

    return _Root;
}

// PrintTree
// Purpose: Prints the tree to the console in prefix notation (for debugging).
// Parameters: _Root - pointer to the root of the tree.
// Returns: Nothing.
// Complexity: O(n), where n is the number of nodes.
void PrintTree(SNode* _Root) {
    if (!_Root) return;

    if (IsOperation(_Root->Value)) {
        string Op;
        switch (_Root->Value) {
        case -1: Op = "+"; break;
        case -2: Op = "-"; break;
        case -3: Op = "*"; break;
        case -4: Op = "/"; break;
        case -5: Op = "%"; break;
        case -6: Op = "^"; break;
        }
        cout << "(" << Op << " ";
        PrintTree(_Root->Left);
        cout << " ";
        PrintTree(_Root->Right);
        cout << ")";
    }
    else {
        cout << _Root->Value;
    }
}

// DeleteTree
// Purpose: Frees all memory allocated for the tree.
// Parameters: _Root - pointer to the root of the tree.
// Returns: Nothing.
// Complexity: O(n), where n is the number of nodes.
void DeleteTree(SNode* _Root) {
    if (!_Root) return;
    DeleteTree(_Root->Left);
    DeleteTree(_Root->Right);
    delete _Root;
}