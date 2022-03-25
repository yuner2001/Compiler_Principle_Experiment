#pragma once

namespace Compiler::Token
{
    class Token
    {
        virtual void description() = 0;
    };

    class PrimitiveType : Token
    {
    };

} // namespace Compiler::Token
