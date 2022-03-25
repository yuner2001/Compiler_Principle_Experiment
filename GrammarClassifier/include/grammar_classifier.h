#pragma once
#include<set>
#include<map>
#include<string>
#include"global.h"
#include"grammar.h"

class GrammarClassifier{
    public:
        Grammar_type Classify(Grammar &gr);
};