/*
Выбрано решение 3 (DeepSeek).

Решение 3 полностью корректно обрабатывает все граничные случаи: 
проверяет корректность номера вершины, наличие файла, существование графа. 
В отличие от решения 1, оно сортирует соседей перед добавлением в очередь, 
что гарантирует детерминированный порядок обхода, важный для воспроизводимости результатов. 
В отличие от решения 2, DeepSeek не содержит русских комментариев, 
использует естественную для C++ нумерацию вершин с 0 и не создаёт избыточных структур 
(отдельные функции для чтения файла или BFS). Весь код компактно помещён в main, что делает его понятным. 
Стиль соответствует современному C++: английские имена, vector, queue, sort.

*/





/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. Имена переменных (file, n, matrix, k, q, i, j, current, neighbors) не в PascalCase
    3. Русский текст в cout и комментариях
    4. Открывающая скобка main на новой строке
*/



//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int main() 
//{
//    string FileName;
//    cout << "Введите имя файла: ";
//    cin >> FileName;
//
//    ifstream file(FileName);
//    if (!file.is_open()) {
//        cout << "Ошибка открытия файла!" << endl;
//        return 1;
//    }
//
//    int n;
//    file >> n;  // Считываем количество вершин
//
//    // Считываем матрицу смежности
//    vector<vector<int>> matrix(n, vector<int>(n));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            file >> matrix[i][j];
//        }
//    }
//    file.close();
//
//    int k;
//    cout << "Введите номер начальной вершины (0-" << n - 1 << "): ";
//    cin >> k;
//
//    // Проверка корректности ввода
//    if (k < 0 || k >= n) {
//        cout << "Ошибка: вершина с номером " << k << " не существует!" << endl;
//        return 1;
//    }
//
//    // BFS алгоритм
//    vector<bool> visited(n, false);  // Массив посещенных вершин
//    vector<int> result;               // Результат обхода
//    queue<int> q;                     // Очередь для BFS
//
//    // Начинаем с вершины k
//    visited[k] = true;
//    q.push(k);
//
//    while (!q.empty()) {
//        int current = q.front();
//        q.pop();
//        result.push_back(current);
//
//        // Собираем всех непосещенных соседей текущей вершины
//        vector<int> neighbors;
//        for (int i = 0; i < n; i++) {
//            if (matrix[current][i] != 0 && !visited[i]) {
//                neighbors.push_back(i);
//            }
//        }
//
//        // Сортируем соседей в порядке возрастания номеров
//        sort(neighbors.begin(), neighbors.end());
//
//        // Добавляем соседей в очередь
//        for (int neighbor : neighbors) {
//            visited[neighbor] = true;
//            q.push(neighbor);
//        }
//    }
//
//    // Выводим результат
//    cout << "Вершины, достижимые из вершины " << k << " (в порядке обхода BFS):" << endl;
//    for (size_t i = 0; i < result.size(); i++) {
//        cout << result[i];
//        if (i < result.size() - 1) {
//            cout << " ";
//        }
//    }
//    cout << endl;
//
//    return 0;
//}



//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// Purpose:
//   Performs BFS traversal on a graph starting from a given vertex.
//   The graph is defined by an adjacency matrix read from a file.
//
// Input:
//   - File name (user input)
//   - File content:
//        first line: number of vertices N
//        next N lines: adjacency matrix N x N (0 = no edge)
//   - Start vertex number (user input, 0-based indexing)
//
// Output:
//   - List of vertices reachable from start vertex in BFS order
//
// Complexity:
//   - Time: O(N²) - due to adjacency matrix traversal
//   - Memory: O(N) - visited array, queue, result vector
//
// Algorithm:
//   1. Initialize visited array and queue
//   2. Add start vertex to queue and mark as visited
//   3. While queue is not empty:
//      - Dequeue vertex, add to result
//      - Find all unvisited neighbors
//      - Sort neighbors in ascending order
//      - Add neighbors to queue and mark as visited
//
// Error handling:
//   - Checks if file exists
//   - Validates vertex count (>0)
//   - Validates start vertex index

int main() {
    string FileName;
    cout << "Enter file name: ";
    cin >> FileName;

    ifstream InputFile(FileName);
    if (!InputFile.is_open()) {
        cout << "Error: Cannot open file!" << endl;
        return 1;
    }

    int VertexCount;
    InputFile >> VertexCount;

    // Check validity of vertex count
    if (VertexCount <= 0) {
        cout << "Error: Number of vertices must be positive!" << endl;
        return 1;
    }

    // Read adjacency matrix
    vector<vector<int>> AdjMatrix(VertexCount, vector<int>(VertexCount));
    for (int Row = 0; Row < VertexCount; ++Row) {
        for (int Col = 0; Col < VertexCount; ++Col) {
            InputFile >> AdjMatrix[Row][Col];
        }
    }
    InputFile.close();

    int StartVertex;
    cout << "Enter start vertex (0-" << VertexCount - 1 << "): ";
    cin >> StartVertex;

    // Validate start vertex
    if (StartVertex < 0 || StartVertex >= VertexCount) {
        cout << "Error: Vertex " << StartVertex << " does not exist!" << endl;
        return 1;
    }

    // BFS algorithm
    vector<bool> Visited(VertexCount, false);   // Visited vertices array
    vector<int> Result;                          // BFS traversal order
    queue<int> Queue;                            // Queue for BFS

    // Start from the given vertex
    Visited[StartVertex] = true;
    Queue.push(StartVertex);

    while (!Queue.empty()) {
        int CurrentVertex = Queue.front();
        Queue.pop();
        Result.push_back(CurrentVertex);

        // Collect all unvisited neighbors of the current vertex
        vector<int> Neighbors;
        for (int NextVertex = 0; NextVertex < VertexCount; ++NextVertex) {
            if (AdjMatrix[CurrentVertex][NextVertex] != 0 && !Visited[NextVertex]) {
                Neighbors.push_back(NextVertex);
            }
        }

        // Sort neighbors in ascending order for deterministic traversal
        sort(Neighbors.begin(), Neighbors.end());

        // Add neighbors to the queue
        for (int Neighbor : Neighbors) {
            Visited[Neighbor] = true;
            Queue.push(Neighbor);
        }
    }

    // Output result
    cout << "Vertices reachable from vertex " << StartVertex << " (BFS order):" << endl;
    for (size_t Index = 0; Index < Result.size(); ++Index) {
        cout << Result[Index];
        if (Index < Result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}