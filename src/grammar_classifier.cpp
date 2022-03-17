#include"grammar_classifier.h"
#include<iostream>
using namespace std;
Grammar_type GrammarClassifier::Classify(Grammar &gr)
{
    std::set<std::string> v_t = gr.getVt();
    std::set<std::string> v_n = gr.getVn();
    std::string s = gr.getS();
    std::vector<std::pair<std::string,std::string>> p = gr.getP();
    std::string::iterator s_it;
    std::vector<std::pair<std::string,std::string>>::iterator p_it;
    // default 3 type
    int type = 3;
    // basic legal check
    // to make sure that there will be no more illegal symbol
    for(p_it = p.begin();p_it != p.end();p_it++)
    {
         for(s_it = p_it->first.begin();s_it != p_it->first.end();s_it++)
            if(!(v_n.end() == v_n.find(std::string(1,*s_it)) || v_t.end() == v_t.find(std::string(1,*s_it))))
                return UNKOWN;
        for(s_it = p_it->second.begin();s_it != p_it->second.end();s_it++)
            if(!(v_n.end() == v_n.find(std::string(1,*s_it)) || v_t.end() == v_t.find(std::string(1,*s_it))))
                return UNKOWN;
    }

    // there must be a implication that it's first part must be "S"
    // and at least it's must contain one symbol which in the vn
    bool is_contain_s = false;
    bool is_contain_vn = false;
    for(p_it = p.begin();p_it != p.end();p_it++)
    {
        if(!is_contain_s && p_it->first == s)
        {
            is_contain_s = true;
        }
        for(s_it = p_it->first.begin();s_it != p_it->first.end();s_it++)
            if(v_n.end() != v_n.find(std::string(1,*s_it)))
            {
                is_contain_vn = true;
                break;
            }
    }
    if(!is_contain_s || !is_contain_vn)
        return UNKOWN;
    
    // epsilon on the right side
    // and the epsilon strings can only appear alone
    // so we don't care other case
    bool ep_on_the_right = false;
    for(p_it = p.begin();p_it != p.end();p_it++)
    {
        if(p_it->second == epsilon)
        {
            ep_on_the_right == true;
        }
    }

    // Identify type 0,1 or type 3,4
    bool is_first_two_type = false;
    for(p_it = p.begin();p_it != p.end();p_it++)
        if(!(p_it->first.size() == 1 && v_n.find(p_it->first) != v_n.end()))
        {
            is_first_two_type = true;
            break;
        }

    // further identify
    // type 0,1
    if(is_first_two_type)
    {
        bool is_CSG = true;
        for(p_it = p.begin();p_it != p.end();p_it++)
        {
            // if epsilon string appears on the right
            // or the length of the right is smaller than the right
            // The only case is this Grammar is a PSG Type Grammar
            if(!ep_on_the_right && p_it->first.size()>p_it->second.size())
            {
                gr.setType(PSG);
                return PSG;
            }
        }
        gr.setType(CSG);
        return CSG;
    } 
    // type 2,3
    else
    {
        bool left = false;
        bool right = false;
        int vt_num;
        int vn_num;
        for(p_it = p.begin();p_it != p.end();p_it++)
        {
            vt_num = 0;
            vn_num = 0;
            left = false;
            right = false;
            // check the position of the only vn symbol  
            if(v_n.end() != v_n.find(std::string(1,p_it->second[0])))
                left = true;
            if(v_n.end() != v_n.find(std::string(1,p_it->second[p_it->second.size()-1])))
                right = true;
            // get the quantity of vn symbols and vt symbols
            for(s_it = p_it->second.begin();s_it != p_it->second.end();s_it++)
            {
                if(v_n.end() != v_n.find(std::string(1,*s_it)))
                    vn_num++;
                if(v_t.end() != v_t.find(std::string(1,*s_it)))
                    vt_num++;
            }
            // 0: epsilon on the right or has only one vn symbol
            // 1: only has one symbol
            // just ignore it
            if(vn_num + vt_num < 2)
                continue;
            
            // the only vn sympol must be the place which is the far left or far right of this string
            if(vn_num > 1 || !left && !right)
            {
                gr.setType(CFG);
                return CFG; 
            } 
        }
        // if it is not CFG,it must be RLG
        gr.setType(RLG);
        return RLG;
    }
}