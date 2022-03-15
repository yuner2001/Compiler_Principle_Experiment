#include"grammar.h"

Grammar::Grammar()
{
    terminal_set.clear();
    none_terminal_set.clear();
    p.clear();
    s.clear();
    gt = UNKOWN;
}

Grammar_type Grammar::getType()
{
    return this->gt;
}

void Grammar::AddATerminal(std::string t)
{
    this->terminal_set.insert(t);
}

void Grammar::AddANoneTerminal(std::string nt)
{
    this->none_terminal_set.insert(nt);
}

void Grammar::AddAP(std::pair<std::string,std::string> imp)
{
    this->p.insert(imp);
}

void Grammar::setS(std::string s)
{
    this->s.clear();
    this->s = s;
}

void Grammar::setType(Grammar_type g)
{
    this->gt = g;
}