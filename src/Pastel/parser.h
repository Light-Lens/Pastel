#pragma once

#include "tokens.h"

namespace Pastel
{
    class parser
    {
    public:
        parser(const std::vector<Tokens::Token>& tokens, const std::string& current_line, const int& line_no);
    };
}
