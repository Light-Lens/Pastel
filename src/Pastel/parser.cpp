#include "../pastelpch.h"
#include "tokens.h"
#include "parser.h"

namespace Pastel
{
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

        // for (int i = 0; i < translation.size(); i++)
        //     std::cout << translation[i] << std::endl;
    }

    void parser::handle_comments(const token& tok)
    {
        translation.push_back(tok.name);
    }

    void parser::handle_includes(const std::vector<token>& tok, const int& start_index)
    {
        if (tok[start_index].name != "include" && tok[start_index].name != "import")
            return;

        std::map<std::vector<token_type>, std::vector<std::string>> cases {
            {
                {token_type::STRING},
                {""}
            },
            {
                {token_type::OPERATOR, token_type::IDENTIFIER, token_type::OPERATOR},
                {"<", "", ">"}
            },
            {
                {token_type::OPERATOR, token_type::IDENTIFIER, token_type::SYMBOL, token_type::IDENTIFIER, token_type::OPERATOR},
                {"<", "", ".", "" ">"}
            }
        };

        translation.push_back("#include");

        for (const auto& entry : cases)
        {
            const std::vector<token_type>& type = entry.first;
            const std::vector<std::string>& value = entry.second;

            for (const auto& token : type)
            {
            }

            for (const auto& id : value)
            {
            }
        }

        // if (tok[start_index + 1].type == STRING)
        //     translation.push_back(tok[start_index + 1].name);

        // else if (tok[start_index + 1].type == OPERATOR && tok[start_index + 2].type == IDENTIFIER && tok[start_index + 3].type == OPERATOR)
        // {
        //     if (tok[start_index + 1].name == "<" && tok[start_index + 2].name == ">")
        //     {
        //         std::string includedPath = tok[start_index + 1].name + tok[start_index + 2].name + tok[start_index + 3].name;
        //         translation.push_back(includedPath);
        //     }
        // }

        // else if (tok[start_index + 1].type == OPERATOR && tok[start_index + 2].type == IDENTIFIER && tok[start_index + 3].type == SYMBOL && tok[start_index + 4].type == IDENTIFIER && tok[start_index + 5].type == OPERATOR)
        // {
        //     if (tok[start_index + 1].name == "<" && tok[start_index + 3].name == "." && tok[start_index + 5].name == ">")
        //     {
        //         std::string includedPath = tok[start_index + 1].name + tok[start_index + 2].name + tok[start_index + 3].name + tok[start_index + 4].name + tok[start_index + 5].name;
        //         translation.push_back(includedPath);
        //     }
        // }
    }
}
