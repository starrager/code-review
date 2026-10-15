/*
Выбрано решение 3.

Решение 3 полностью корректно обрабатывает все граничные случаи(неверный ввод, выход по 0).
В отличие от решения 1, оно использует современную случайную генерацию вместо устаревшего rand(), 
что обеспечивает высокое качество случайности.В отличие от решения 2, 
3 вариант не содержит русских комментариев и предлагает надёжные длины паролей(8 / 12 / 16 вместо 4 / 8 / 12).
Код разделён на класс с чёткими методами, что повышает читаемость и расширяемость.
Реализована уникальная функция повторной генерации пароля без перезапуска программы.
Стиль кода соответствует современному C++.
*/





//#include <iostream>
//#include <string>
//#include <random>
//#include <ctime>
//
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






/*
FIXME:
    1. Отсутствует copyright в первой строке
    2. PasswordGenerator generator - должно быть CPasswordGenerator (префикс C)
    3. Имена методов не в PascalCase
    4. Имена переменных не в PascalCase

*/

//int main() {
//    PasswordGenerator generator;
//    int choice;
//
//    std::cout << "Welcome to the Password Generator!\n";
//
//    do {
//        generator.showLevelInfo();
//        std::cout << "\nSelect complexity level (0-3): ";
//        std::cin >> choice;
//
//        if (choice >= 1 && choice <= 3) {
//            std::string password = generator.generate(choice);
//
//            std::cout << "\nGenerated password: " << password << std::endl;
//            std::cout << "Password length: " << password.length() << " characters\n";
//
//            char again;
//            std::cout << "\nGenerate another password of the same level? (y/n): ";
//            std::cin >> again;
//
//            while (again == 'y' || again == 'Y') {
//                password = generator.generate(choice);
//                std::cout << "\nNew password: " << password << std::endl;
//                std::cout << "Generate another? (y/n): ";
//                std::cin >> again;
//            }
//        }
//        else if (choice != 0) {
//            std::cout << "\nError! Please select a level from 1 to 3.\n";
//        }
//
//    } while (choice != 0);
//
//    std::cout << "\nGoodbye!\n";
//
//    return 0;
//}



//FIXTO:

// Copyright (c) 2026 Student Tarakanov. All rights reserved.
#include <iostream>
#include <limits>
#include "PassGen.h"

using namespace std;


// Main function.
// Displays welcome message and complexity level menu.
// Prompts user to select level (1-3 or 0 to exit).
// Generates and displays password of selected level.
// Offers to generate another password of the same level.
// Handles invalid input (letters, symbols).
int main() {
    CPasswordGenerator Generator;
    int Choice;

    cout << "Password Generator.\n";

    do {
        Generator.ShowLevelInfo();
        cout << "\nSelect complexity level (0-3): ";    // Create password generator object
        cin >> Choice;                                  // User's complexity level choice

        // Handle invalid input (letters, symbols)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError. Please enter a number.\n";
            continue;
        }

        if (Choice >= 1 && Choice <= 3) {
            string Password = Generator.Generate(Choice);

            if (Password.empty()) {
                cout << "\nError: Failed to generate password.\n";
                continue;
            }

            cout << "\nGenerated password: " << Password << endl;
            cout << "Password length: " << Password.length() << " characters\n";

            char Again;
            cout << "\nGenerate another password of the same level? (y/n): ";
            cin >> Again;

            // Loop while user wants to generate more passwords
            while (Again == 'y' || Again == 'Y') {
                Password = Generator.Generate(Choice);
                cout << "\nNew password: " << Password << endl;
                cout << "Generate another? (y/n): ";
                cin >> Again;
            }
        }
        else if (Choice != 0) {
            cout << "\nError. Please select a level from 1 to 3.\n";
        }

    } while (Choice != 0);

    cout << "\nDone.\n";

    return 0;
}