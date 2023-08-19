#include "../pastelpch.h"
#include "../utils/strings.h"
#include "lexer.h"

namespace Pastel
{
    lexer::lexer(std::fstream& file)
    {
        while (std::getline(file, current_line))
        {
            std::vector<std::string> a = parser();
            for (int i = 0; i < a.size(); i++)
                std::cout << a[i] << std::endl;

            ++current_line_no;
        }
    }

    std::vector<std::string> lexer::parser()
    {
        std::string tok;
        std::vector<std::string> tokens;

        for (int i = 0; i < current_line.size(); i++)
        {
            tok += current_line[i];

            if (tok == "include")
                tok = "#include";
        }

        tokens.push_back(tok);
        return tokens;
    }
}
