#include"input_handle.h"
#include<iostream>
InputHandler::InputHandler()
{

}

// input format: {{Vt},{},P,S}{A->b,C->d...}
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
            aGrammar.AddANoneTerminal(std::string(1,*it));
        it++;
    }
    it += 3;
    // scan terminal set
    while(*it != '}')
    {
        if(*it != ',')
            aGrammar.AddATerminal(std::string(1,*it));
        it++;
    }
    it += 4;
    // scan S
    aGrammar.setS(std::string(1,*it));
    it+=3;
    // scan the p set
    std::string left_part;
    std::string right_part;
    left_part.clear();
    right_part.clear();
    while(*it != '}')
    {
        left_part.clear();
        right_part.clear();
        while(*it != '-')
        {
            left_part.append(1,*it);
            it++;
        }
        it+=2;
        while(*it != ',' && *it != '}')
        {
            right_part.append(1,*it);
            it++;    
        }
        aGrammar.AddAP(std::pair<std::string,std::string>(left_part,right_part));
        if(*it == '}')
            break;
        it++;
    }
    return aGrammar;
}