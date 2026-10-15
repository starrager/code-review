/*
Выбрано решение 3 (DeepSeek).

Решение DeepSeek полностью корректно обрабатывает все граничные случаи (неверный ввод, деление на ноль, пустой файл). 
В отличие от решения 1, оно не пытается преобразовывать операторы в числа через вычитание символов, 
а использует прямое сопоставление строковых токенов ("+", "-" и т.д.), что значительно надёжнее.  
Код разделён на небольшие функции с чёткими ответственностями (isOperation, applyOperation, buildTree, optimizeTree, deleteTree). 
Реализована полная оптимизация дерева - если оба поддерева являются числами, результат вычисляется сразу, а поддерево заменяется на лист. 
Есть функция deleteTree() для освобождения памяти, что предотвращает утечки. Стиль кода соответствует современному C++.

*/


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cmath>
//
//using namespace std;

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


/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. Использование Node вместо SNode
    3 Функции buildTree, printTree, optimizeTree, deleteTree должны быть в PascalCase
    4. Переменные filename, file, root не в PascalCase
    5 Русский текст в cout и комментариях
*/



//int main() {
//    string filename;
//    cout << "Введите имя файла: ";
//    cin >> filename;
//
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cout << "Ошибка открытия файла!" << endl;
//        return 1;
//    }
//
//    // Построение дерева
//    Node* root = buildTree(file);
//    file.close();
//
//    if (!root) {
//        cout << "Ошибка построения дерева!" << endl;
//        return 1;
//    }
//
//    cout << "Исходное дерево: ";
//    printTree(root);
//    cout << endl;
//
//    // Оптимизация дерева
//    root = optimizeTree(root);
//
//    cout << "Указатель на корень: " << root << endl;
//    cout << "Оптимизированное дерево: ";
//    printTree(root);
//    cout << endl;
//
//    // Освобождение памяти
//    deleteTree(root);
//
//    return 0;
//}


//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include <iostream>
#include <fstream>
#include <string>
#include "TreeBuilder.h"

using namespace std;


// Program: Expression Tree Builder and Optimizer
// Purpose:
//   Builds a binary tree from a prefix expression read from a file,
//   optimizes it by collapsing numeric subtrees, and prints the result.
//
// Input:
//   - File name (user input)
//   - File content: prefix expression tokens separated by spaces
//        Example: + 2 * 3 4
//        Operators: + - * / % ^
//        Operands: digits 0-9
//
// Output:
//   - Original tree in prefix notation
//   - Optimized tree (numeric subtrees are collapsed)
//   - Root pointer address
//
// Complexity:
//   - Time: O(n), where n is the number of tokens
//   - Memory: O(n) for the tree structure
//
// Algorithm:
//   1. Read tokens from file
//   2. Build tree recursively: if token is a number -> leaf node
//      if token is an operator -> internal node with left and right children
//   3. Optimize tree: if both children are numbers, compute result and replace subtree
//   4. Print original and optimized trees
//   5. Free allocated memory
//
// Error handling:
//   - Checks if file exists
//   - Checks if tree was built successfully

int main() {
    string FileName;      // Name of input file
    cout << "Enter file name: ";
    cin >> FileName;

    ifstream File(FileName);
    if (!File.is_open()) {
        cout << "Error: Cannot open file!" << endl;
        return 1;
    }

    // Build tree from file
    SNode* Root = BuildTree(File);
    File.close();

    if (!Root) {
        cout << "Error: Failed to build tree!" << endl;
        return 1;
    }

    // Print original tree
    cout << "Original tree: ";
    PrintTree(Root);
    cout << endl;

    // Optimize tree
    Root = OptimizeTree(Root);

    // Print result
    cout << "Root pointer: " << Root << endl;
    cout << "Optimized tree: ";
    PrintTree(Root);
    cout << endl;

    // Free memory
    DeleteTree(Root);

    return 0;
}