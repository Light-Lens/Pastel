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
            handle_comment(first_token);

        // if (tokens[0].type == COMMENT)
        //     translation.push_back(tokens[0].name);

        // else if (tokens[0].type == KEYWORD && tokens[1].type == STRING)
        // {
        //     if (tokens[0].name == "include")
        //     {
        //         translation.push_back("#include");
        //         translation.push_back(tokens[1].name);
        //     }
        // }

        // else if (tokens[0].type == SYMBOL && tokens[1].type == KEYWORD && tokens[2].type == STRING)
        // {
        //     if (tokens[0].name == "#" && tokens[1].name == "include")
        //     {
        //         translation.push_back("#include");
        //         translation.push_back(tokens[2].name);
        //     }
        // }

        // else if (tokens[0].type == KEYWORD && tokens[1].type == OPERATOR && tokens[2].type == IDENTIFIER && tokens[3].type == OPERATOR)
        // {
        //     if (tokens[0].name == "include" && tokens[1].name == "<" && tokens[3].name == ">")
        //     {
        //         translation.push_back("#include");
        //         translation.push_back(tokens[2].name + tokens[3].name + tokens[4].name);
        //     }
        // }

        // else if (tokens[0].type == SYMBOL && tokens[1].type == KEYWORD && tokens[2].type == OPERATOR && tokens[3].type == IDENTIFIER && tokens[4].type == SYMBOL &&  tokens[5].type == IDENTIFIER && tokens[6].type == OPERATOR)
        // {
        //     if (tokens[0].name == "#" && tokens[1].name == "include" && tokens[2].name == "<" && tokens[6].name == ">")
        //     {
        //         translation.push_back("#include");
        //         translation.push_back(tokens[2].name + tokens[3].name + tokens[4].name + tokens[5].name + tokens[6].name);
        //     }
        // }

        // else if (tokens[0].type == SYMBOL && tokens[1].type == KEYWORD && tokens[2].type == OPERATOR && tokens[3].type == IDENTIFIER && tokens[4].type == OPERATOR)
        // {
        //     if (tokens[0].name == "#" && tokens[1].name == "include" && tokens[2].name == "<" && tokens[4].name == ">")
        //     {
        //         translation.push_back("#include");
        //         translation.push_back(tokens[2].name + tokens[3].name + tokens[4].name);
        //     }
        // }

        for (int i = 0; i < translation.size(); i++)
            std::cout << translation[i] << std::endl;
    }
}
