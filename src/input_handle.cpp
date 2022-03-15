#include"input_handle.h"
#include<iostream>
InputHandler::InputHandler()
{

}
// input format: {{Vt},{}}
Grammar InputHandler::GetUnclassifiedGrammar(std::string input_string)
{
    Grammar aGrammar;
    bool vn_finished = false;
    bool vt_finished = false;
    int brackets_nums = 0;
    int rbrackets_nums = 0;
    std::string::iterator it = input_string.begin();
    it+=2;
    // scan none terminal set
    while(*it != '}')
    {
        if(*it != ',')
            aGrammar.none_terminal_set.insert(std::string(1,*it));
        it++;
    }
    it += 2;
    // scan terminal set
    while(*it != '}')
    {
        if(*it != ',')
            aGrammar.terminal_set.insert(std::string(1,*it));
        it++;
    }
    it += 4;
    // scan S
    aGrammar.s = *it;
    it+=3;
    // scan the p set
    std::string left_part;
    std::string right_part;
    left_part.clear();
    right_part.clear();
    while(*it != '}')
    {
        while(*it != '-')
        {
            left_part.append(1,*it);
            it++;
        }
        it+=2;
        while(*it != ',' && *it != '}')
        {
            right_part.append(1,*it);    
        }
        std::cout<<left_part<<", "<<right_part<<std::endl;
        if(*it == '}')
            break;
        it++;
    }
    return aGrammar;
}