#include <iostream>
#include"grammar.h"
#include"input_handle.h"
#include"grammar_classifier.h"

void ShowType(Grammar_type gt)
{
    switch (gt)
    {
        case PSG:
            std::cout<<"PSG"<<std::endl;
            break;
        case CSG:
            std::cout<<"CSG"<<std::endl;
            break;
        case CFG:
            std::cout<<"CFG"<<std::endl;
            break;
        case RLG:
            std::cout<<"RLG"<<std::endl;
            break;
        default:
            std::cout<<"unknow"<<std::endl;
            break;
    }
    std::cout<<gt<<std::endl;
}
void String2Type(std::string st)
{
    InputHandler ipt = InputHandler();
    GrammarClassifier gf = GrammarClassifier();
    Grammar aGrammar;
    aGrammar = ipt.GetUnclassifiedGrammar(st);
    ShowType(gf.Classify(aGrammar));
}
int main(int, char**) {
    String2Type("{{S,A,B,C,D,E},{a},P,S}{S->ACaB,Ca->aaC,CB->DB,CB->E,aD->Da,AD->AC,aE->Ea,AE->?}");
    String2Type("{{S,B,C,D},{a,b,c},P,S}{S->aSBC,S->aBC,CB->CD,CD->BD,BD->BC,aB->ab,bB->bb,bC->bc,cC->cc}");
    String2Type("{{Z,S,A,B,C},{a,b,c},P,Z}{Z->SC,S->aAc,A->aAc,A->bBb,C->aCb,C->?,B->bB,B->?}");
    String2Type("{{Z,U,V},{0,1},P,Z}{Z->U0,Z->V1,U->Z1,U->1,V->Z0,V->0}");
}
