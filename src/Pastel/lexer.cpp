#include "../pastelpch.h"
#include "../utils/strings.h"
#include "lexer.h"

namespace Pastel
{
    struct lexer::Token
    {
        std::string original_line;
        std::string translated_line;
    };

    // lexer::lexer(const std::string& current_line, const int& current_line_no)
    lexer::lexer(std::fstream& file)
    {
        while (std::getline(file, current_line))
        {
            std::vector<lexer::Token> a = tokenizer();
            for (size_t i = 0; i < a.size(); i++)
            {
                std::cout << a[i].original_line << std::endl;
                std::cout << a[i].translated_line << std::endl;
            }

            std::cout << std::endl;

            ++current_line_no;
        }
    }

    std::vector<lexer::Token> lexer::tokenizer()
    {
        std::string tok;
        std::vector<Token> tokens;

        for (int i = 0; i < current_line.size(); i++)
        {
            tok += current_line[i];
            tokens.push_back({"", tok});

            // if (utils::is_empty(tok))
            //     tokens.push_back({tok, tok});

            // else
            //     tokens.push_back({tok, tok});
        }

        return tokens;
    }
}
