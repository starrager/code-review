/*
FIXME:
1. Отсутствует copyright в первой строке
2. setlocale(LC_ALL, "ru") - русский язык
3. N - не описательное имя
4. input, output - имена не в PascalCase
5. Магические строки "input.txt", "output.txt"
6. Русский текст в cout
7. Переменные циклов i, j - не описательные
8. Открывающие скобки for, if на новых строках
*/


//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//#include <iomanip>
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    ifstream input("input.txt");
//    ofstream output("output.txt");
//    int N;
//    input >> N;
//    if (N <= 1 || N >= 80) {
//        cerr << "Некорректный размер доски: " << N << ". Должно быть 1 < N < 80" << endl;
//        input.close();
//        output.close();
//        return 1;
//    }
//    vector<vector<int>> board(N, vector<int>(N));
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            input >> board[i][j];
//        }
//    }
//
//
//    vector<vector<int>> dp(N, vector<int>(N, 0));
//
//    dp[N - 1][0] = board[N - 1][0];
//
//    for (int i = N - 2; i >= 0; i--) {
//        dp[i][0] = dp[i + 1][0] + board[i][0];
//    }
//
//    for (int j = 1; j < N; j++) {
//        dp[N - 1][j] = dp[N - 1][j - 1] + board[N - 1][j];
//    }
//
//    for (int i = N - 2; i >= 0; i--) {
//        for (int j = 1; j < N; ++j) {
//            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + board[i][j];
//        }
//    }
//    output << dp[0][N - 1];
//    cout << "Значение " << dp[0][N - 1] << " записано в файл";
//}


// FIXTO:


// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const string INPUT_FILE_NAME = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";

int main() {
    int BoardSize;

    ifstream InputFile(INPUT_FILE_NAME.c_str());
    ofstream OutputFile(OUTPUT_FILE_NAME.c_str());

    InputFile >> BoardSize;

    // Read board
    vector<vector<int>> Board(BoardSize, vector<int>(BoardSize));
    for (int Row = 0; Row < BoardSize; ++Row) {
        for (int Col = 0; Col < BoardSize; ++Col) {
            InputFile >> Board[Row][Col];
        }
    }

    // DP table
    vector<vector<int>> DP(BoardSize, vector<int>(BoardSize, 0));

    // Start position: left bottom corner
    DP[BoardSize - 1][0] = Board[BoardSize - 1][0];

    // Fill first column (move only UP)
    for (int Row = BoardSize - 2; Row >= 0; --Row) {
        DP[Row][0] = DP[Row + 1][0] + Board[Row][0];
    }

    // Fill last row (move only RIGHT)
    for (int Col = 1; Col < BoardSize; ++Col) {
        DP[BoardSize - 1][Col] = DP[BoardSize - 1][Col - 1] + Board[BoardSize - 1][Col];
    }

    // Fill the rest (move UP or RIGHT, choose minimum)
    for (int Row = BoardSize - 2; Row >= 0; --Row) {
        for (int Col = 1; Col < BoardSize; ++Col) {
            DP[Row][Col] = min(DP[Row + 1][Col], DP[Row][Col - 1]) + Board[Row][Col];
        }
    }

    // Answer in top right corner
    OutputFile << DP[0][BoardSize - 1];
}