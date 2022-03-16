#pragma once
#include<set>
#include<vector>
#include<string>
#include<utility>
#include"global.h"

class Grammar{
    public:
        Grammar();
        Grammar_type getType();
        void AddATerminal(std::string t);
        void AddANoneTerminal(std::string nt);
        void AddAP(std::pair<std::string,std::string> imp);
        void setS(std::string s);
        void setType(Grammar_type g);
        std::set<std::string> getVt();
        std::set<std::string> getVn();
        std::vector<std::pair<std::string,std::string>> getP();
        std::string getS();
    private:
        std::set<std::string> terminal_set;
        std::set<std::string> none_terminal_set;
        std::vector<std::pair<std::string,std::string>> p;
        std::string s;
        Grammar_type gt;
};