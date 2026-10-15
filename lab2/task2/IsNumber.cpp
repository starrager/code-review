/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. Отсутствует #include "IsNumber.h"
    3. Отсутствует #include <cctype> для isdigit
    4. Имя параметра str не описательное, нет префикса _ (_String)
    5. Переменные start, i не в PascalCase 
    6. Нет фигурных скобок у if

*/

//bool IsNumber(const  string& str) {
//    if (str.empty()) return false;
//    int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
//    for (int i = start; i < str.length(); ++i) {
//        if (!isdigit(str[i])) return false;
//    }
//    return start < str.length();
//}


//FIXTO:

#include <cctype>
using namespace std;
#include "IsNumber.h"


bool IsNumber(const string& _String) {
    // Empty string is not a valid number
    if (_String.empty()) {
        return false;
    }

    // Skip optional leading '+' or '-' sign
    int StartIndex = (_String[0] == '-' || _String[0] == '+') ? 1 : 0;

    // Check remaining characters - all must be digits
    for (int CharIndex = StartIndex; CharIndex < (int)_String.length(); ++CharIndex) {
        if (!isdigit(_String[CharIndex])) {
            return false;
        }
    }

    // At least one digit must exist
    return StartIndex < (int)_String.length();
}