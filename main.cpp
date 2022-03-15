#include <iostream>
#include"grammar.h"
#include"input_handle.h"
int main(int, char**) {
    InputHandler ipt = InputHandler();
    Grammar aGrammar;
    aGrammar = ipt.GetUnclassifiedGrammar("{{A,B,C,S},{1,2},P,S}{S->A,A->B,B->C,C->1,C->2}");
    std::cout << "Hello, world!\n";
}
