#include"input_handle.h"

InputHandler::InputHandler()
{

}

Grammar InputHandler::GetUnclassifiedGrammar(std::string input_string)
{
    Grammar aGrammar;
    bool vn_finished = false;
    bool vt_finished = false;
    int brackets_nums = 0;
    int rbrackets_nums = 0;
    std::string::iterator it = input_string.begin();
    while(brackets_nums < 2)
    {
        switch (*it)
        {
            case '{':
                brackets_nums++;
                break;         
            default:
                break;
        }
        it++;
    }
    // scan none terminal set
    while(*it != '}')
    {
        if(*it != ',' || *it != ' ')
            aGrammar.none_terminal_set.insert(std::string(1,*it));
        it++;
    }
    while(*it != '{')
        it++;
    it++;
    // scan the terminal set
    while(*it != '}')
    {
        if(*it != ',' || *it != ' ')
            aGrammar.terminal_set.insert(std::string(1,*it));
        it++;
    }
    while(*it != '{')
        it++;
    it++;
    // scan the p set
}