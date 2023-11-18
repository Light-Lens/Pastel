#include "pastelpch.h"
#include "utils/Utils/strings.h"
#include "Pastel/Errors/errors.h"
#include "Pastel/tokens.h"
#include "parser.h"

namespace Pastel
{
    parser::parser(const std::vector< std::vector<token> >& tokenized_code, const std::vector<std::string>& original_lines)
    {
        for (int i = 0; i < tokenized_code.size(); i++)
        {
            this->current_line = original_lines[i];
            this->translator(tokenized_code[i]);
            ++this->current_line_no;
        }

        for (int i = 0; i < this->translation.size(); i++)
        {
            for (int j = 0; j < this->translation[i].size(); j++)
                std::cout << this->translation[i][j] << std::endl;

            std::cout << std::endl;
        }
    }

    // translate pastel code to c++ code
    void parser::translator(const std::vector<token>& tokens)
    {
        const size_t num_tokens = tokens.size();
        if (num_tokens == 0)
            return;

        for (int i = 0; i < num_tokens; i++)
        {
            const token_type type = tokens[i].type;
            const std::string name = tokens[i].name;

            if (type == KEYWORD)
            {
                std::cout << name << std::endl;
                // if (contains_keywords(tokens, include_keywords))
                //     handle_includes(tokens, i);
            }
        }

        // for (int i = 0; i < num_tokens; i++)
        // {
        //     const token_type type = tokens[i].type;
        //     const std::string name = tokens[i].name;

        //     if (type == COMMENT)
        //     {
        //         translation.push_back({name});
        //         break;
        //     }

        //     else if (type == KEYWORD)
        //     {
        //         if (contains_keywords(tokens, include_keywords))
        //             handle_includes(tokens, i);
        //     }
        // }
    }

    // /**
    // * Handles processing of '#include' directives in the token stream.
    // *
    // * This function extracts the include path from the tokens and adds it to the translation.
    // *
    // * @param tok The vector of tokens to be processed.
    // * @param start_index The index of the starting token for processing.
    // */
    // void parser::handle_includes(const std::vector<token>& tok, int& start_index)
    // {
    //     // increment the start index to move to the next token
    //     start_index++;

    //     // store the include path
    //     std::string include_path;

    //     // check if the starting token is a string literal
    //     if (tok[start_index].type == STRING)
    //         include_path += tok[start_index].name;

    //     // check if the starting token is an opening angle bracket '<'
    //     else if (tok[start_index].type == OPERATOR && tok[start_index].name == "<")
    //     {
    //         include_path += tok[start_index].name;

    //         // move to the next token
    //         start_index++;

    //         // check for unexpected end of tokens
    //         if (start_index >= tok.size())
    //             errors::runtime("unexpected end of tokens after '<'", current_line, current_line_no);

    //         // process tokens until closing angle bracket '>' is encountered
    //         while (start_index < tok.size() && tok[start_index].name != ">")
    //         {
    //             if (tok[start_index].name == "<")
    //                 errors::fatal("unexpected restart of tokens after '<'", current_line, current_line_no);

    //             include_path += tok[start_index].name;
    //             start_index++;
    //         }

    //         // check for missing closing angle bracket '>'
    //         if (start_index >= tok.size() || tok[start_index].name != ">")
    //             errors::runtime("unexpected end of tokens, missing closing '>'", current_line, current_line_no);

    //         // move to the next token after '>'
    //         include_path += tok[start_index].name;
    //         start_index++;

    //         // check for unexpected token after '#include' directive
    //         if (start_index < tok.size())
    //             errors::runtime("unexpected token after '>'", current_line, current_line_no);
    //     }

    //     // handle the case when the token type is not recognized
    //     else
    //         errors::runtime("#include expects \"FILENAME\" or <FILENAME>", current_line, current_line_no);

    //     // add the include path to the translation
    //     //TODO: If include_path endswith ".pastel", replace it with ".h".
    //     if (utils::strings::endswith(include_path, ".pastel\""))
    //         include_path = utils::strings::replace_last(include_path, ".pastel\"", ".h\"");

    //     else if (utils::strings::endswith(include_path, ".pastel>"))
    //         include_path = utils::strings::replace_last(include_path, ".pastel>", ".h>");

    //     translation.push_back({"#include", include_path});
    // }

    // /**
    // * Check if any of the specified keywords exist in the given tokens.
    // * 
    // * This function searches through the token names to determine if any of the provided
    // * keywords are present.
    // * 
    // * @param tokens The list of tokens to search through.
    // * @param list_of_keywords The keywords to search for.
    // * @return True if any of the keywords are found in the tokens, false otherwise.
    // */
    // bool parser::contains_keywords(const std::vector<token>& tokens, const std::vector<std::string>& list_of_keywords)
    // {
    //     for (const auto& keyword : list_of_keywords)
    //     {
    //         // Check if any token's name matches the current keyword using std::any_of,
    //         // if a match is found, return true; otherwise, continue checking with the next keyword.
    //         if (std::any_of(tokens.begin(), tokens.end(), [&keyword](const token& t) { return t.name == keyword; }))
    //             return true;
    //     }

    //     return false;
    // }
}
