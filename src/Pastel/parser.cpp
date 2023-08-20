#include "../pastelpch.h"
#include "tokens.h"
#include "parser.h"

namespace Pastel
{
    void parser::translator(const std::vector<tokens::token>& tokens)
    {
        std::string tok;
        std::vector<std::string> translation;

        for (int i = 0; i < tokens.size(); i++)
        {
            tok += tokens[i].name;

            if (tok == "include")
                tok = "#include";

            else if (tok == "let")
                tok = "auto";

            else if (tok == "string")
                tok = "std::string";

            else if (tok == "fun")
                tok = "void";
        }

        translation.push_back(tok);

        for (int i = 0; i < translation.size(); i++)
            std::cout << translation[i] << std::endl;
    }
}
