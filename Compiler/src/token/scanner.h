#pragma once

#include <memory>
#include "../utils/char_utils.h"

namespace Compiler::Token
{
    using namespace Compiler::CharUtils;
 
    class Scanner
    {

    private:
        std::unique_ptr<CharStream> charStream;
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
    };
} // namespace Compiler::Token