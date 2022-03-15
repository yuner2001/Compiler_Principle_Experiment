#pragma once
#include<set>
#include<map>
#include<string>
#include<utility>
#include"global.h"

class Grammar{
    friend class InputHandler;
    public:
        Grammar();
        Grammar_type getType();
        void AddATerminal(std::string t);
        void AddANoneTerminal(std::string nt);
        void AddAP(std::pair<std::string,std::string> imp);
        void setS(std::string s);
        void setType(Grammar_type g);
    private:
        std::set<std::string> terminal_set;
        std::set<std::string> none_terminal_set;
        std::map<std::string,std::string> p;
        std::string s;
        Grammar_type gt;
};