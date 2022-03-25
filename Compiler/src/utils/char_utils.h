#pragma once

#include <sstream>
#include <string>

namespace Compiler::CharUtils
{
    using CharStream = std::stringstream;
    using Char = char;
    using String = std::string;

    inline bool isUpperCase(Char ch)
    {
        return ch >= 'A' && ch <= 'Z';
    }

    inline bool isLowerCase(Char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }

    inline bool isDigit(Char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    inline bool isLetter(Char ch)
    {
        return isUpperCase(ch) || isLowerCase(ch);
    }

    inline bool isLetterDigit(Char ch)
    {
        return isLetter(ch) || isDigit(ch);
    }

    inline bool isOperator(Char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=';
    }

    inline bool isPunctuation(Char ch)
    {
        return ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ',' || ch == ';';
    }
} // namespace Compiler
