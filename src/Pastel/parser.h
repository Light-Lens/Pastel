#pragma once

#include "tokens.h"

namespace Pastel
{
    class parser
    {
    public:
        int current_line_no;
        std::string current_line;

    public:
        void translator(std::vector<Tokens::Token> tokens);
    };
}
