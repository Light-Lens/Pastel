#include "../pastelpch.h"
#include "../utils/strings.h"
#include "errors.h"
#include "tokens.h"
#include "parser.h"

namespace Pastel
{
    parser::parser(const std::vector< std::vector<token> >& tokenized_code)
    {
        for (int i = 0; i < tokenized_code.size(); i++)
        {
            translator(tokenized_code[i]);
            ++current_line_no;
        }

        for (int i = 0; i < translation.size(); i++)
        {
            for (int j = 0; j < translation[i].size(); j++)
                std::cout << translation[i][j] << std::endl;

            std::cout << std::endl;
        }
    }

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
                translation.push_back({name});
                break;
            }

            else if (type == KEYWORD)
            {
                handle_includes(tokens, i);
            }
        }
    }

    void parser::handle_comments(const token& tok)
    {
        translation.push_back({tok.name});
    }

    // handle includes of external lib.
    void parser::handle_includes(const std::vector<token>& tok, const int& start_index)
    {
        if (!contains_keywords(tok, include_keywords))
            return;

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
                    errors::runtime("unexpected end of tokens after '<'", current_line_no);

                while (i < tok.size())
                {
                    include_path += tok[i].name;
                    i++;
                }

                std::cout << "[" << include_path << ", " << i << " : " << tok.size() << "]\n";
                if (i >= tok.size())
                {
                    // std::string error_detail = "missing terminating " + std::string(1, str_char_symbol) + " character";
                    // errors::lexical(error_detail, current_line_no);
                }






                // if (i < tok.size())
                // {
                //     while (tok[i].name != ">")
                //     {
                //         if (i < tok.size())
                //         {
                //             include_path += tok[i].name;
                //             i++;
                //         }

                //         else
                //         {
                //             errors::runtime("unexpected end of tokens", current_line_no);
                //             break;
                //         }
                //     }

                //     if (i < tok.size() && tok[i].name == ">")
                //     {
                //         include_path += tok[i].name;
                //         i++;
                //     }

                //     else
                //         errors::runtime("missing closing '>'", current_line_no);
                // }

                // else
                //     errors::runtime("unexpected end of tokens after '<'", current_line_no);

                break;
            }

            else
                errors::runtime("#include expects \"FILENAME\" or <FILENAME>", current_line_no);
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
