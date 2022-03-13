#pragma once
#include<set>
#include<map>
#include<string>
#include"global.h"
#include"input_handle.h"

class Grammar{
    friend class InputHandler;
    public:
        Grammar();
        Grammar_type getType();
    private:
        std::set<std::string> terminal_set;
        std::set<std::string> none_terminal_set;
        std::map<std::string,std::string> p;
        std::string s;
        Grammar_type gt;
};