/*
FIXME: 
    1.Отсутствует copyright в первой строке
    2. setlocale(LC_ALL, "Russian") - русский язык
    3. int N, Z - несколько переменных в одной строке
    4. Переменные не в PascalCase , nalog - транслит    
    7. Магическая строка "археолог.txt" - имя файла на русском языке
    8. Переменные циклов i, s - не описательные
    9. Открывающие скобки main, for, if на новых строках
    10. Русский текст в cout и комментариях
    11. findAnswer - имя не в PascalCase (должно быть FindAnswer)
    12. Параметры должны иметь префикс _
    13. Нет пробелов после #include <fstream> и #include <vector>
       
*/

//#include <iostream>
//#include<fstream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    int N, Z;
//    ifstream f1("археолог.txt");
//    f1 >> N >> Z;
//    vector<int> weight(N + 1);
//    vector<int> nalog(N + 1);
//    for (int i = 1; i <= N; i++) {
//        f1 >> weight[i];//считывание весов и налогов
//    }
//    for (int i = 1; i <= N; i++) {
//        f1 >> nalog[i];
//    }
//
//    int maxWeight = 0;
//    for (int i = 1; i <= N; i++) {
//        maxWeight += weight[i];//нахождение макс веса для массива
//    }
//
//    vector<vector<int>> dp(N + 1, vector<int>(maxWeight + 1, 10000000));
//    dp[0][0] = 0;
//    for (int i = 1; i <= N; i++)
//    {
//        for (int s = 0; s <= maxWeight; s++)
//        {
//            dp[i][s] = dp[i - 1][s];
//            if (s >= weight[i] && dp[i - 1][s - weight[i]] != 10000000)
//            {
//                dp[i][s] = min(dp[i][s], dp[i - 1][s - weight[i]] + nalog[i]);
//            }
//        }
//    }
//    int minNalog = 10000000;
//    int bestWeight = -1;
//
//    for (int s = Z + 1; s <= maxWeight; s++) {
//        if (dp[N][s] < minNalog) {
//            minNalog = dp[N][s];
//            bestWeight = s;
//        }
//    }
//    cout << "Минимальный налог: " << minNalog << endl;
//    cout << "Суммарный вес: " << bestWeight << endl;
//    findAnswer(dp, N, bestWeight, weight, nalog);
//    cout << endl;
//    return 0;
//}




//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#include <fstream>
#include <iostream>
#include <vector>

#include "FindAnswer.h"

const int INFINITE_TAX = 10000000;   // Sentinel value for "unreachable state"
const int INVALID_WEIGHT = -1;       // Sentinel value for "no solution found"
const std::string INPUT_FILE_NAME = "input.txt";

int main() {
    int ArtefactCount;   
    int WeightThreshold;

    std::ifstream InputFile(INPUT_FILE_NAME.c_str());
    InputFile >> ArtefactCount >> WeightThreshold;

    // Arrays for artefact data (1-based indexing)
    std::vector<int> ArtefactWeight(ArtefactCount + 1);
    std::vector<int> ArtefactTax(ArtefactCount + 1);

    // Read artefact weights
    for (int ArtefactIdx = 1; ArtefactIdx <= ArtefactCount; ++ArtefactIdx) {
        InputFile >> ArtefactWeight[ArtefactIdx];
    }

    // Read artefact taxes
    for (int ArtefactIdx = 1; ArtefactIdx <= ArtefactCount; ++ArtefactIdx) {
        InputFile >> ArtefactTax[ArtefactIdx];
    }

    // Calculate total weight of all artefacts
    int TotalWeightSum = 0;
    for (int ArtefactIdx = 1; ArtefactIdx <= ArtefactCount; ++ArtefactIdx) {
        TotalWeightSum += ArtefactWeight[ArtefactIdx];
    }

    // DP table: DP[i][w] = minimum tax to achieve weight 'w' using first 'i' artefacts
    std::vector<std::vector<int>> DP(ArtefactCount + 1,
        std::vector<int>(TotalWeightSum + 1, INFINITE_TAX));
    DP[0][0] = 0;

    // Fill DP table
    for (int ArtefactIdx = 1; ArtefactIdx <= ArtefactCount; ++ArtefactIdx) {
        for (int CurrentWeight = 0; CurrentWeight <= TotalWeightSum; ++CurrentWeight) {
            // Option 1: skip current artefact
            DP[ArtefactIdx][CurrentWeight] = DP[ArtefactIdx - 1][CurrentWeight];

            // Option 2: take current artefact (if possible)
            if (CurrentWeight >= ArtefactWeight[ArtefactIdx] &&
                DP[ArtefactIdx - 1][CurrentWeight - ArtefactWeight[ArtefactIdx]] != INFINITE_TAX) {

                DP[ArtefactIdx][CurrentWeight] = std::min(DP[ArtefactIdx][CurrentWeight],
                    DP[ArtefactIdx - 1][CurrentWeight - ArtefactWeight[ArtefactIdx]] + ArtefactTax[ArtefactIdx]);
            }
        }
    }

    // Find best solution: weight > Z with minimum tax
    int MinTax = INFINITE_TAX;
    int BestWeight = INVALID_WEIGHT;

    for (int CurrentWeight = WeightThreshold + 1; CurrentWeight <= TotalWeightSum; ++CurrentWeight) {
        if (DP[ArtefactCount][CurrentWeight] < MinTax) {
            MinTax = DP[ArtefactCount][CurrentWeight];
            BestWeight = CurrentWeight;
        }
    }

    // Output results
    std::cout << "Minimum tax: " << MinTax << '\n';
    std::cout << "Total weight: " << BestWeight << '\n';
    std::cout << "Selected artefacts: ";

    // Restore and print indices of selected artefacts
    FindAnswer(DP, ArtefactCount, BestWeight, ArtefactWeight, ArtefactTax);
    std::cout << '\n';

    return 0;
}