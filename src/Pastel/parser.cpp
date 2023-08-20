#include "../pastelpch.h"
#include "parser.h"

namespace Pastel
{
    parser::parser(const std::vector<Tokens::Token>& tokens, const std::string& current_line, const int& line_no)
    {
        for (int i = 0; i < tokens.size(); i++)
            std::cout << tokens[i].name;

        std::cout << std::endl;
    }
}
