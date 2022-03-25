#include <iostream>
#include "token.h"
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
        
        for (auto &&token : tokens)
        {
            cout << token->description() << endl;
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

        shared_ptr<Token> token;

        switch (scanType)
        {
        case ScanType::Integer:
            token = std::make_shared<Integer>(str);
            break;
        case ScanType::String:
            token = std::make_shared<StringLiteral>(str);
            break;
        case ScanType::Word:
            token = PrimitiveType::lookup(str);
            if (token == nullptr)
                token = fetchIdentifier(str);
            break;
        case ScanType::Operator:
            token = Operator::lookup(str);
            break;
        case ScanType::Punctuation:
            token = Punctuation::lookup(str);
            break;
        case ScanType::NoScanning:
            break;
        default:
            cout << "当前扫描状态出错！" << endl;
            break;
        }

        scanType = ScanType::NoScanning;
        if (token != nullptr)
            tokens.push_back(token);
    }

    shared_ptr<Identifier> Scanner::fetchIdentifier(std::string name)
    {
        shared_ptr<Identifier> identifier(nullptr);
        for (auto &id : identifiers)
        {
            if (id->name == name)
            {
                identifier = id;
                break;
            }
        }
        if (identifier == nullptr)
        {
            identifier = make_shared<Identifier>(name);
            identifiers.push_back(identifier);
        }
        return identifier;
    }
} // namespace Compiler::Token