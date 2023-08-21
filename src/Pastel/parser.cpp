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

        for (int i = 0; i < tokens.size(); i++)
        {
            const token_type type = tokens[i].type;
            const std::string name = tokens[i].name;

            if (type == COMMENT)
            {
                translation.push_back(name);
                break;
            }

            else if (type == KEYWORD)
                handle_includes(tokens, i);
                handle_variables(tokens, i);
        }

        for (int i = 0; i < translation.size(); i++)
            std::cout << translation[i] << std::endl;
    }

    void parser::handle_comments(const token& tok)
    {
        translation.push_back(tok.name);
    }

    // handle includes of external lib.
    void parser::handle_includes(const std::vector<token>& tok, const int& start_index)
    {
        if (tok[start_index].name != "include" && tok[start_index].name != "import")
            return;

        std::string include_path;
        for (int i = start_index+1; i < tok.size(); i++)
            include_path += tok[i].name;

        translation.push_back("#include" + include_path);
    }

    // handle variables
    void parser::handle_variables(const std::vector<token>& tok, const int& start_index)
    {
        if (tok[start_index].name != "include" && tok[start_index].name != "import")
            return;

        std::string include_path;
        for (int i = start_index+1; i < tok.size(); i++)
            include_path += tok[i].name;

        translation.push_back("#include" + include_path);
    }
}
