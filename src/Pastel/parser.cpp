#include "../pastelpch.h"
#include "../utils/strings.h"
#include "errors.h"
#include "tokens.h"
#include "parser.h"

namespace Pastel
{
    parser::parser(const std::vector< std::vector<token> >& tokenized_code, const std::vector<std::string>& original_lines)
    {
        for (int i = 0; i < tokenized_code.size(); i++)
        {
            current_line = original_lines[i];
            translator(tokenized_code[i]);
            ++current_line_no;
        }

        // for (int i = 0; i < translation.size(); i++)
        // {
        //     for (int j = 0; j < translation[i].size(); j++)
        //         std::cout << translation[i][j] << std::endl;

            // std::cout << std::endl;
        // }
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

            if (type == COMMENT)
            {
                translation.push_back({name});
                break;
            }

            else if (type == KEYWORD)
            {
                if (contains_keywords(tokens, include_keywords))
                    handle_includes(tokens, i);
            }
        }
    }

    // handle includes of external lib.
    void parser::handle_includes(const std::vector<token>& tok, const int& start_index)
    {
        std::string include_path;
        for (int i = start_index+1; i < tok.size(); i++)
        {
            if (tok[i].type == STRING)
            {
                include_path += tok[i].name;
                break;
            }

            else if (tok[i].type == OPERATOR && tok[i].name == "<")
            {
                include_path += tok[i].name;
                i++;
                if (i >= tok.size())
                    errors::runtime("unexpected end of tokens after '<'", current_line, current_line_no);



                bool has_closing_char_encountered = false;
                while (i < tok.size())
                {
                    if (tok[i].name == "<" || has_closing_char_encountered)
                        errors::fatal("invalid argument", current_line, current_line_no);

                    // if (tok[i].name == "<")
                    //     errors::fatal("invalid argument", current_line, current_line_no);

                    if (tok[i].name == ">" && !has_closing_char_encountered)
                        has_closing_char_encountered = true;

                    include_path += tok[i].name;
                    i++;
                }

                include_path += tok[i].name;



                if (i >= tok.size() || tok[i].name != ">")
                    errors::runtime("unexpected end of tokens, missing closing '>'", current_line, current_line_no);

                break;
            }

            else
                errors::runtime("#include expects \"FILENAME\" or <FILENAME>", current_line, current_line_no);
        }

        translation.push_back({"#include", include_path});
    }

    /**
    * Check if any of the specified keywords exist in the given tokens.
    * 
    * This function searches through the token names to determine if any of the provided
    * keywords are present.
    * 
    * @param tokens The list of tokens to search through.
    * @param list_of_keywords The keywords to search for.
    * @return True if any of the keywords are found in the tokens, false otherwise.
    */
    bool parser::contains_keywords(const std::vector<token>& tokens, const std::vector<std::string>& list_of_keywords)
    {
        for (const auto& keyword : list_of_keywords)
        {
            // Check if any token's name matches the current keyword using std::any_of,
            // if a match is found, return true; otherwise, continue checking with the next keyword.
            if (std::any_of(tokens.begin(), tokens.end(), [&keyword](const token& t) { return t.name == keyword; }))
                return true;
        }

        return false;
    }
}
