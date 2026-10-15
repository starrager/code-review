//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько 
//имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится 
//более трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

/*
FIXME:
	1. Отсутствует copyright 
	2. Имена переменных не в PascalCase: i, k, n, nz, oz, tz, thz, fz и т.д.
	3. Переменные не описательные 
	4. Несколько переменных в одной строке
	5. Переменные циклов i - не описательная
	6. Нет комментариев к логике работы программы
*/


//#include <iostream>
//using namespace std;
//int main()
//{
//	int i, k, n, nz, _nz, oz, _oz, tz, _tz, thz, _thz, fz, _fz;
//	cout << "input k: ";
//	cin >> k;
//	cout << "input n: ";
//	cin >> n;
//	nz = k - 1;
//	oz = 0;
//	tz = 0;
//	thz = 0;
//	fz = 0;
//	for (i = 2;i <= n;i++)
//	{
//		_nz = nz;
//		_oz = oz;
//		_tz = tz;
//		_thz = thz;
//		_fz = fz;
//		nz = _nz * (k - 1) + _oz * (k - 1) + _tz * (k - 1) + _thz * (k - 1);
//		oz = _nz;
//		tz = _oz;
//		thz = _tz;
//		if (i < 6)
//			fz = _thz + _fz * (k - 1);
//		else
//			fz = _thz + _fz * k;
//	}
//	cout << fz;
//	return 0;
//}




// FIXTO:

#include <iostream>
using namespace std; 

int main() {
    int Base;           
    int DigitCount;

    cout << "Enter base K (2-10): ";
    cin >> Base;
    cout << "Enter number of digits N (1<N<20): ";
    cin >> DigitCount;

    // Validate input (optional, but good practice)
    if (Base < 2 || Base > 10) {
        cout << "Error: K must be between 2 and 10" << endl;
        return 1;
    }
    if (DigitCount <= 1 || DigitCount >= 20) {
        cout << "Error: N must be between 2 and 19" << endl;
        return 1;
    }
    if (DigitCount + Base >= 26) {
        cout << "Error: N + K must be < 26" << endl;
        return 1;
    }

    // DP states:
    // ZeroCount1   - numbers ending with 1 zero
    // ZeroCount2   - numbers ending with 2 zeros
    // ZeroCount3   - numbers ending with 3 zeros
    // ZeroCount4+  - numbers ending with 4 or more zeros (invalid, will be discarded)
    // ValidCount   - total valid numbers with no more than 3 consecutive zeros

    long long EndWith1Zero = Base - 1;   // First digit can't be zero
    long long EndWith2Zeros = 0;
    long long EndWith3Zeros = 0;
    long long ValidCount = 0;             // Numbers with 4+ zeros (invalid)

    for (int Pos = 2; Pos <= DigitCount; ++Pos) {
        long long Prev1Zero = EndWith1Zero;
        long long Prev2Zeros = EndWith2Zeros;
        long long Prev3Zeros = EndWith3Zeros;
        long long PrevInvalid = ValidCount;

        // New numbers ending with 1 zero: add non-zero digit to any previous
        EndWith1Zero = (Prev1Zero + Prev2Zeros + Prev3Zeros + PrevInvalid) * (Base - 1);

        // New numbers ending with 2 zeros: add zero to numbers ending with 1 zero
        EndWith2Zeros = Prev1Zero;

        // New numbers ending with 3 zeros: add zero to numbers ending with 2 zeros
        EndWith3Zeros = Prev2Zeros;

        // Invalid numbers (4+ zeros): add zero to numbers ending with 3 zeros
        // and also carry over previous invalid numbers (they stay invalid)
        if (Pos < 6) {
            ValidCount = Prev3Zeros + PrevInvalid * (Base - 1);
        }
        else {
            ValidCount = Prev3Zeros + PrevInvalid * Base;
        }
    }

    // Result is the total of all valid states (no more than 3 consecutive zeros)
    double Result = static_cast<double>(EndWith1Zero + EndWith2Zeros + EndWith3Zeros);

    cout << "Result: " << Result << endl;

    return 0;
}


