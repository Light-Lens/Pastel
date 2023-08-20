#include "../pastelpch.h"
#include "parser.h"

namespace Pastel
{
    parser::parser(const std::vector<Tokens::Token>& tokens, const std::string& current_line, const int& line_no)
    {
        std::string token;
        std::vector<std::string> translation;

        for (int i = 0; i < tokens.size(); i++)
        {
            token += tokens[i].name;

            if (token == "include")
                token = "#include";

            else if (token == "let")
                token = "auto";

            else if (token == "string")
                token = "std::string";

            else if (token == "fun")
                token = "void";
        }

        translation.push_back(token);

        for (int i = 0; i < translation.size(); i++)
            std::cout << translation[i] << std::endl;
    }
}
