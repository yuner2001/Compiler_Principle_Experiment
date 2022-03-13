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