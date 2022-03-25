#pragma once

#include "token.h"
#include "../utils/char_utils.h"

namespace Compiler::Token
{
    using namespace Compiler::CharUtils;
    using namespace std;
 
    class Scanner
    {

    private:
        unique_ptr<CharStream> charStream;
        vector<shared_ptr<Token>> tokens;
        vector<shared_ptr<Identifier>> identifiers;
        CharStream lexemeBuilder;

        enum class ScanType
        {
            NoScanning,
            Integer,
            String,
            Word,
            Operator,
            Punctuation
        };

        ScanType scanType = ScanType::NoScanning;
        int col;
        int row;

    public:
        Scanner(std::unique_ptr<CharStream> CharStream);

        void scan();

    private:
        void inputChar(Char ch, Char lastCh);
        void saveToken();
        shared_ptr<Identifier> fetchIdentifier(std::string name);
    };
} // namespace Compiler::Token