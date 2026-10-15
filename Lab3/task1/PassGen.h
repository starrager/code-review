// Copyright (c) 2026 Student Tarakanov. All rights reserved.

#pragma once

#include <string>
#include <random>
#include <ctime>

// A class for generating passwords with three complexity levels.
// Allows you to generate passwords of 8, 12, or 16 characters
// using lowercase and uppercase letters, numbers, and special characters.
class CPasswordGenerator {
private:
    std::string m_Lowercase;   // Lowercase Latin letters (a-z)
    std::string m_Uppercase;   // Uppercase Latin letters (A-Z)
    std::string m_Digits;      // Digits (0-9)
    std::string m_Symbols;     // Special characters (!@#$%^&*...)
    mutable std::mt19937 m_Rng; // Mersenne Twister random number generator

    // Returns the character set for the specified complexity level.
    std::string GetCharset(int _Level) const;

    // Returns the password length for the specified complexity level.
    int GetLength(int _Level) const;

public:
    // Constructor. Initializes the random number generator.
    CPasswordGenerator();

    // Generates a password of the specified complexity level.
    std::string Generate(int _Level);

    // Displays information about password complexity levels.
    void ShowLevelInfo() const;
};