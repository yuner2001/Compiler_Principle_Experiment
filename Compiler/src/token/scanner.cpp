#include <iostream>
#include "scanner.h"

namespace Compiler::Token
{
    using namespace std;

    Scanner::Scanner(unique_ptr<CharStream> charStream) : charStream(move(charStream))
    {
    }

    void Scanner::scan()
    {
        Char lastCh = '\0';
        row = col = 0;
        while (!this->charStream->eof())
        {
            Char ch = charStream->get();
            inputChar(ch, lastCh);
            lastCh = ch;
        }
    }

    void Scanner::inputChar(Char ch, Char lastCh)
    {
        col++;
        if (scanType == ScanType::String && ch != '"')
        {
            lexemeBuilder << ch;
        }
        else if (ch == '"')
        {
            if (scanType != ScanType::String)
            {
                scanType = ScanType::String;
                lexemeBuilder = CharStream();
            }
            else
            {
                saveToken();
            }
        }
        else if (isLetter(ch))
        {
            if (scanType == ScanType::NoScanning)
            {
                scanType = ScanType::Word;
                lexemeBuilder = CharStream();
            }
            lexemeBuilder << ch;
        }
        else if (isDigit(ch))
        {
            if (scanType != ScanType::Word && scanType != ScanType::Integer)
            {
                scanType = ScanType::Integer;
                lexemeBuilder = CharStream();
            }
            lexemeBuilder << ch;
        }
        else if (isOperator(ch))
        {
            if (scanType != ScanType::Operator)
            {
                saveToken();

                scanType = ScanType::Operator;
                lexemeBuilder = CharStream();
            }
            lexemeBuilder << ch;
        }
        else if (isPunctuation(ch))
        {
            saveToken();

            scanType = ScanType::Punctuation;
            lexemeBuilder = CharStream();
            lexemeBuilder << ch;

            saveToken();
        }
        else if (ch == ' ' || ch == '\r' || ch == '\n')
        {
            if (scanType != ScanType::NoScanning)
            {
                saveToken();

                scanType = ScanType::NoScanning;
                if ((ch == '\n' && lastCh != '\r') || ch == '\r')
                {
                    row++;
                    col = 0;
                }
            }
        }
    }

    void Scanner::saveToken()
    {
        String str = lexemeBuilder.str();

        // TODO：存放到TOKEN表

        if (scanType != ScanType::NoScanning)
            cout << str << endl;

        switch (scanType)
        {
        case ScanType::Integer:
            /* code */
            break;
        case ScanType::String:
            /* code */
            break;
        case ScanType::Word:
            /* code */
            break;
        case ScanType::Operator:
            /* code */
            break;
        case ScanType::Punctuation:
            /* code */
            break;
        case ScanType::NoScanning:
            break;
        default:
            cout << "当前扫描状态出错！" << endl;
            break;
        }

        scanType = ScanType::NoScanning;
    }
} // namespace Compiler::Token