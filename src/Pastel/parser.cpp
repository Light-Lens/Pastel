#include "../pastelpch.h"
#include "parser.h"

namespace Pastel
{
    void parser::translator(std::vector<Tokens::Token> tokens)
    {
        // std::cout << current_line_no << ". " << current_line << std::endl;
        for (int i = 0; i < tokens.size(); i++)
            std::cout << tokens[i].name;

        std::cout << std::endl;



        // std::string tok;

        // for (int i = 0; i < current_line.size(); i++)
        // {
        //     tok += current_line[i];

        //     if (tok == "include")
        //         tok = "#include";
        // }
    }
}
