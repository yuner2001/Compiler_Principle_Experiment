#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "utils/char_utils.h"
#include "token/scanner.h"

using namespace std;

int main(int argc, char const *argv[])
{
    using namespace Compiler::CharUtils;
    using namespace Compiler::Token;

    ifstream file;
    file.open("./res/hello.c");

    unique_ptr<Compiler::CharUtils::CharStream> cs(new CharStream());
    Char ch = file.get();
    while (!file.eof())
    {
        *cs << ch;
        ch = file.get();
    }
    
    Scanner scanner(move(cs));
    scanner.scan();

    return 0;
}
