#pragma once

#include <string>
#include <sstream>
#include <memory>
#include <vector>

namespace Compiler::Token
{
    class Token
    {
    public:
        virtual std::string description() = 0;
    };

    class PrimitiveType : public Token
    {
    private:
        static std::vector<PrimitiveType> token;

    public:
        PrimitiveType(std::string typeName) : typeName(typeName)
        {
        }
        static std::vector<std::shared_ptr<PrimitiveType>> all;
        static std::shared_ptr<PrimitiveType> lookup(std::string typeName);

        const std::string typeName;
        std::string description() override { return std::string("<PrimitiveType, ") + (this->typeName) + ">"; }
    };

    class Identifier : public Token
    {
    public:
        const std::string name;
        Identifier(std::string name) : name(name)
        {
        }

        std::string description() override { return std::string("<Identifier, ") + name + ">"; }
    };

    class Literal : public Token
    {
    protected:
        const std::string raw;

    public:
        Literal(std::string raw) : raw(raw) {}
    };

    template <typename Value>
    class Number : public Literal
    {
    private:
        Value value;

    public:
        Number(std::string raw) : Literal(raw)
        {
            std::stringstream ss(raw);
            Value value;
            ss >> value;
            this->value = value;
        }
    };

    class Integer : public Number<int>
    {
    public:
        Integer(std::string raw) : Number(raw) {}
        std::string description() override { return std::string("<IntLiteral, ") + raw + ">"; }
    };

    class StringLiteral : public Literal
    {
    public:
        StringLiteral(std::string raw) : Literal(raw) {}
        std::string description() override { return std::string("<StringLiteral, \"") + raw + "\">"; }
    };

    class Operator : public Token
    {
    protected:
        const std::string raw;
        static std::vector<std::shared_ptr<Operator>> all;

    public:
        Operator(std::string raw) : raw(raw) {}
        std::string description() override { return std::string("<Operator, \"") + raw + "\">"; }
        static std::shared_ptr<Operator> lookup(std::string raw);
    };

    class Punctuation : public Token
    {
    protected:
        const std::string raw;
        static std::vector<std::shared_ptr<Punctuation>> all;

    public:
        Punctuation(std::string raw) : raw(raw) {}
        std::string description() override { return std::string("<Punctuation, \"") + raw + "\">"; }
        static std::shared_ptr<Punctuation> lookup(std::string raw);
    };
} // namespace Compiler::Token
