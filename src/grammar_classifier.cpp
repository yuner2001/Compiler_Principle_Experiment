#include"grammar_classifier.h"

void GrammarClassifier::Classify(Grammar &gr)
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
    for(p_it = p.begin();p_it != p.end();p_it++)
    {
         for(s_it = p_it->first.begin();s_it != p_it->first.end();s_it++)
            if(!(v_n.end() == v_n.find(std::string(1,*s_it)) || v_t.end() == v_t.find(std::string(1,*s_it))))
                return;
        for(s_it = p_it->second.begin();s_it != p_it->second.end();s_it++)
            if(!(v_n.end() == v_n.find(std::string(1,*s_it)) || v_t.end() == v_t.find(std::string(1,*s_it))))
                return;
    }

    // there must be a implication that it's first part must be "S"
    // and at least it's must contain one symbol which in the vn
    bool is_contain_s = false;
    bool is_contain_vn = true;
    for(p_it = p.begin();p_it != p.end();p_it++)
    {
        if(!is_contain_s && p_it->first == s)
        {
            is_contain_s = true;
        }
        for(s_it = p_it->first.begin();s_it != p_it->first.end();s_it++)
            if(v_n.end() == v_n.find(std::string(1,*s_it)))
            {
                is_contain_vn = false;
                break;
            }
    }
    if(!is_contain_s || !is_contain_vn)
        return;

    // identify 0,1 or 3,4
    bool is_first_two_type = true;
    for(p_it = p.begin();p_it != p.end();p_it++)
        if(p_it->first.size() == 1 && v_n.find(p_it->first) != v_n.end())
            is_first_two_type == false;

    // identify
    int vt_num;
    int vn_num;
    if(is_first_two_type)
    {
        bool is_CSG = true;
        for(p_it = p.begin();p_it != p.end();p_it++)
        {
            if(p_it->first.size()>p_it->second.size())
            {
                gr.setType(PSG);
                return;
            }
        }
        gr.setType(CSG);
        return;
    } 
    else
    {
        
    }

}