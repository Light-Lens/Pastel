#include "../pastelpch.h"
#include "../utils/strings.h"
#include "tokens.h"
#include "parser.h"

namespace Pastel
{
    // translate pastel code to c++ code
    void parser::translator(const std::vector<token>& tokens)
    {
        const size_t num_tokens = tokens.size();
        if (num_tokens == 0)
            return;

        const token& first_token = tokens[0];
        if (first_token.type == COMMENT)
            handle_comments(first_token);

        else if (first_token.type == KEYWORD)
            handle_includes(tokens, 0);

        else if (first_token.type == SYMBOL)
            handle_includes(tokens, 1);

        for (int i = 0; i < translation.size(); i++)
            std::cout << translation[i] << std::endl;
    }

    void parser::handle_comments(const token& tok)
    {
        translation.push_back(tok.name);
    }

    // handle the usage of include any external lib.
    void parser::handle_includes(const std::vector<token>& tok, const int& start_index)
    {
        if (tok[start_index].name != "include" && tok[start_index].name != "import")
            return;

        std::string include_path;
        for (int i = start_index+1; i < tok.size(); i++)
            include_path += tok[i].name;

        translation.push_back("#include " + include_path);
    }
}
