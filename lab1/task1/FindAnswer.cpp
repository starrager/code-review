/* FIXME:  Имя функции findAnswer должно быть FindAnswer(PascalCase),
        Параметры должны иметь префикс _ ,
        Имена параметров k и s не описательные,
        nalog на транслите, (tax),
        Русский язык в cout , 
        Открывающая скобка функции на новой строке,

*/


//void findAnswer(const vector<vector<int>>& dp, int k, int s, vector<int>& weight, vector<int>& nalog)
//{
//    if (k == 0) {
//        return;
//    }
//    if (dp[k][s] == dp[k - 1][s]) {
//        findAnswer(dp, k - 1, s, weight, nalog);
//    }
//    else {
//        cout << "берем артефакт с индексом " << k << ", ";
//        findAnswer(dp, k - 1, s - weight[k], weight, nalog);
//    }
//}
//







//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#include <iostream>
using namespace std;
#include "FindAnswer.h"

void FindAnswer(const vector<vector<int>>& _DP,
    int _ArtefactIndex,
    int _RemainingWeight,
    const vector<int>& _WeightList,
    const vector<int>& _TaxList) {

    // Base case: no more artefacts to check
    if (_ArtefactIndex == 0) {
        return;
    }

    // If tax didn't change, artefact was NOT taken
    if (_DP[_ArtefactIndex][_RemainingWeight] == _DP[_ArtefactIndex - 1][_RemainingWeight]) {
        FindAnswer(_DP, _ArtefactIndex - 1, _RemainingWeight, _WeightList, _TaxList);
    }
    else {
        // Artefact WAS taken
        cout << _ArtefactIndex << " ";
        FindAnswer(_DP, _ArtefactIndex - 1, _RemainingWeight - _WeightList[_ArtefactIndex],
            _WeightList, _TaxList);
    }
}