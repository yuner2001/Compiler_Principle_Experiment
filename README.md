# FoolFoolGrammarClassifier
## 编译原理: 一个笨笨的文法分类器
支持PSG,CSG,CFG,RLG四种文法的分类(含扩展CFG与扩展RLG，归于对应种类)，目前实在太忙辣辣所以只有黑乎乎的控制台呜呜呜，所以叫他笨笨文法分类器。
使用时包含用头文件 [grammar_classifier](./src/grammar_classifier.cpp),调用其成员函数Classify即可，欢迎各位朋友一起完善。

**demo**:
依次输入得文法:
1. {{S,A,B,C,D,E},{a},P,S}{S->ACaB,Ca->aaC,CB->DB,CB->E,aD->Da,AD->AC,aE->Ea,AE->?}
2. {{S,B,C,D},{a,b,c},P,S}{S->aSBC,S->aBC,CB->CD,CD->BD,BD->BC,aB->ab,bB->bb,bC->bc,cC->cc}
3. {{Z,S,A,B,C},{a,b,c},P,Z}{Z->SC,S->aAc,A->aAc,A->bBb,C->aCb,C->?,B->bB,B->?}
4. {{Z,U,V},{0,1},P,Z}{Z->U0,Z->V1,U->Z1,U->1,V->Z0,V->0}
5. {{S,A,B},{a,b},P,S}{S->aB,S->bA,A->a,A->aS,A->bAA,B->b,B->bS,B->aBB} 
 
(?表示空串)  
依次对应得识别结果:  
<img src = 'img/new.png'>

