/*
FIXME:
    1. Отсутствует copyright в первой строке
	2. Отсутствует разделение на .h и .cpp (реализация внутри класса)
	3. Переменные не в PascalCase
	4. Имена методов не в PascalCase
	5. Параметры без префикса _ .(_Level)
	6. Нет const для методов, которые не меняют состояние: showLevelInfo() const, getCharset() const, getLength() const

*/


//class PasswordGenerator {
//private:
//    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
//    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    std::string digits = "0123456789";
//    std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
//
//    std::mt19937 rng;
//
//    std::string getCharset(int level) {
//        switch (level) {
//        case 1:
//            return lowercase;
//        case 2:
//            return lowercase + uppercase + digits;
//        case 3:
//            return lowercase + uppercase + digits + symbols;
//        default:
//            return lowercase;
//        }
//    }
//
//    int getLength(int level) {
//        switch (level) {
//        case 1:
//            return 8;
//        case 2:
//            return 12;
//        case 3:
//            return 16;
//        default:
//            return 8;
//        }
//    }
//
//public:
//    PasswordGenerator() {
//        rng.seed(std::time(nullptr));
//    }
//
//    std::string generate(int level) {
//        std::string charset = getCharset(level);
//        int length = getLength(level);
//
//        std::uniform_int_distribution<int> dist(0, charset.length() - 1);
//
//        std::string password;
//        for (int i = 0; i < length; i++) {
//            password += charset[dist(rng)];
//        }
//
//        return password;
//    }
//
//    void showLevelInfo() {
//        std::cout << "\n=== Password Complexity Levels ===\n";
//        std::cout << "1 - Easy (8 characters, lowercase letters only)\n";
//        std::cout << "2 - Medium (12 characters, lowercase/uppercase letters + digits)\n";
//        std::cout << "3 - Strong (16 characters, lowercase/uppercase letters + digits + special characters)\n";
//        std::cout << "0 - Exit\n";
//    }
//};



//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include <iostream>
#include "PassGen.h"

using namespace std;


// Constructor of the CPasswordGenerator class.
// Initializes character sets (lowercase and uppercase letters, numbers, special characters)
// and the random number generator m_Rng using the current time.
CPasswordGenerator::CPasswordGenerator():
      m_Lowercase("abcdefghijklmnopqrstuvwxyz"),
      m_Uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
      m_Digits("0123456789"),
      m_Symbols("!@#$%^&*()_+-=[]{}|;:,.<>?"),
      m_Rng(static_cast<unsigned int>(time(nullptr))) {
}


// Returns a character set based on the selected difficulty level.
// Parameters:
// _Level - difficulty level: 1 - easy, 2 - medium, 3 - hard.
// Returns:
// A string with valid characters for generating a password.
// Notes:
// Easy: lowercase letters only.
// Medium: lowercase and uppercase letters + numbers.
// Hard: lowercase and uppercase letters + numbers + special characters.
string CPasswordGenerator::GetCharset(int _Level) const {
    switch (_Level) {
    case 1:
        return m_Lowercase;
    case 2:
        return m_Lowercase + m_Uppercase + m_Digits;
    case 3:
        return m_Lowercase + m_Uppercase + m_Digits + m_Symbols;
    default:
        return m_Lowercase;
    }
}

// Returns the password length depending on the selected complexity level.
// Parameters:
// _Level - complexity level: 1 - easy, 2 - medium, 3 - difficult.
// Returns:
// Password length: 8, 12, or 16 characters.
int CPasswordGenerator::GetLength(int _Level) const {
    switch (_Level) {
    case 1:
        return 8;
    case 2:
        return 12;
    case 3:
        return 16;
    default:
        return 8;
    }
}

// Generates a random password based on the selected complexity level.
// Parameters:
// _Level - complexity level: 1 - easy, 2 - medium, 3 - hard.
// Returns:
// The generated password as a string.
// Notes:
// The mt19937 generator (Mersenne Twister) is used for high-quality randomness.
// If the character set is empty, an empty string is returned.
// Complexity: O(n) time, where n is the password length.
string CPasswordGenerator::Generate(int _Level) {
    string Charset = GetCharset(_Level);
    int Length = GetLength(_Level);

    if (Charset.empty()) {
        return "";
    }

    uniform_int_distribution<int> Dist(0, static_cast<int>(Charset.size()) - 1);

    string Password;
    Password.reserve(Length);

    for (int i = 0; i < Length; ++i) {
        Password += Charset[Dist(m_Rng)];
    }

    return Password;
}
// Displays information about password complexity levels.
// Displays three levels:
// 1 - Easy (8 characters, lowercase letters only)
// 2 - Medium (12 characters, letters + numbers)
// 3 - Complex (16 characters, letters + numbers + special characters)
// 0 - Exit the program
void CPasswordGenerator::ShowLevelInfo() const {
    cout << "\n Password Complexity Levels \n";
    cout << "1 - Easy (8 chars, lowercase only)\n";
    cout << "2 - Medium (12 chars, letters + digits)\n";
    cout << "3 - Strong (16 chars, letters + digits + symbols)\n";
    cout << "0 - Exit\n";
}