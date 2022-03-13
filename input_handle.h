#include<set>
#include<map>
#include<string>
#include"grammar.h"

class InputHandler
{
    public:
        InputHandler();
        Grammar GetUnclassifiedGrammar(std::string input_string);
};