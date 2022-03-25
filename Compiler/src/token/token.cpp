#include "token.h"

namespace Compiler::Token
{

    std::vector<std::shared_ptr<PrimitiveType>> PrimitiveType::all(0);

    std::shared_ptr<PrimitiveType> PrimitiveType::lookup(std::string typeName)
    {
        if (PrimitiveType::all.size() <= 0)
        {
            all.push_back(std::make_shared<PrimitiveType>(std::string("void")));
            all.push_back(std::make_shared<PrimitiveType>(std::string("int")));
            all.push_back(std::make_shared<PrimitiveType>(std::string("char")));
        }
        for (auto &&pt : PrimitiveType::all)
        {
            if (pt->typeName == typeName)
                return pt;
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Operator>> Operator::all(0);

    std::shared_ptr<Operator> Operator::lookup(std::string raw)
    {
        if (all.size() <= 0)
        {
            all.push_back(std::make_shared<Operator>(std::string("=")));
            all.push_back(std::make_shared<Operator>(std::string("+")));
            all.push_back(std::make_shared<Operator>(std::string("-")));
            all.push_back(std::make_shared<Operator>(std::string("*")));
            all.push_back(std::make_shared<Operator>(std::string("/")));
            all.push_back(std::make_shared<Operator>(std::string("++")));
            all.push_back(std::make_shared<Operator>(std::string("--")));
        }
        for (auto &&pt : all)
        {
            if (pt->raw == raw)
                return pt;
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Punctuation>> Punctuation::all(0);

    std::shared_ptr<Punctuation> Punctuation::lookup(std::string raw)
    {
        if (all.size() <= 0)
        {
            all.push_back(std::make_shared<Punctuation>(std::string("(")));
            all.push_back(std::make_shared<Punctuation>(std::string(")")));
            all.push_back(std::make_shared<Punctuation>(std::string("[")));
            all.push_back(std::make_shared<Punctuation>(std::string("]")));
            all.push_back(std::make_shared<Punctuation>(std::string("{")));
            all.push_back(std::make_shared<Punctuation>(std::string("}")));
            all.push_back(std::make_shared<Punctuation>(std::string(";")));
            all.push_back(std::make_shared<Punctuation>(std::string(",")));
        }
        for (auto &&pt : all)
        {
            if (pt->raw == raw)
                return pt;
        }
        return nullptr;
    }

} // namespace Compiler::Token
