#include "../pastelpch.h"
#include "lexer.h"

#include "../utils/strings.h"
#include "errors.h"

namespace Pastel
{
    std::vector<token> lexer::tokenizer()
    {
        std::string tok;
        std::vector<token> tokens;

        for (int i = 0; i < current_line.size(); i++)
        {
            tok += current_line[i];

            if (utils::is_empty(tok))
                tok.clear();

            else if (current_line[i] == '/' && current_line[i+1] == '/')
            {
                i++;
                while (i < current_line.size())
                {
                    tok += current_line[i];
                    i++;
                }

                i--;

                tokens.push_back({token_type::COMMENT, tok});
                tok.clear();
                break;
            }

            else if (is_paren(current_line[i]) && tok.size() == sizeof(current_line[i]))
            {
                tokens.push_back({token_type::PAREN, tok});
                tok.clear();
            }

            else if (is_symbol(current_line[i]) && tok.size() == sizeof(current_line[i]))
            {
                tokens.push_back({token_type::SYMBOL, tok});
                tok.clear();
            }

            else if (is_operator(current_line[i]) && tok.size() == sizeof(current_line[i]))
            {
                tokens.push_back({token_type::OPERATOR, tok});
                tok.clear();
            }

            else if (is_identifier(tok))
            {
                i++;
                while (i < current_line.size() && is_identifier(std::string(1, current_line[i])))
                {
                    tok += current_line[i];
                    i++;
                }

                i--;

                if (is_keyword(tok))
                    tokens.push_back({token_type::KEYWORD, tok});

                else
                    tokens.push_back({token_type::IDENTIFIER, tok});

                tok.clear();
            }

            else if (is_float(tok))
            {
                i++;
                while (i < current_line.size() && is_float(std::string(1, current_line[i])))
                {
                    tok += current_line[i];
                    i++;
                }

                i--;

                if (is_int(tok))
                    tokens.push_back({token_type::INT, tok});

                else
                    tokens.push_back({token_type::FLOAT, tok});

                tok.clear();
            }

            else if (tok == "'" || tok == "\"")
            {
                char str_char_symbol = tok[0];

                i++;
                while (i < current_line.size() && current_line[i] != str_char_symbol)
                {
                    tok += current_line[i];
                    i++;
                }

                tok += current_line[i];

                if (i >= current_line.size())
                    errors::runtime("Unterminated char at line " + std::to_string(current_line_no));

                if (current_line[i] == '"')
                    tokens.push_back({token_type::STRING, tok});

                if (current_line[i] == '\'')
                    tokens.push_back({token_type::CHAR, tok});

                tok.clear();
            }

            else
            {
                tokens.push_back({token_type::UNKNOWN, tok});
                tok.clear();
            }
        }

        return tokens;
    }

    bool lexer::is_keyword(const std::string& str)
    {
        // for (int i = 0; i < (keywords->size() / keywords[0].size()); i++)
        // {
        //     std::cout << "[" << str << ", " << keywords[i] << "]\n";
        //     if (str == keywords[i])
        //         return true;
        // }

        for (int i = 0; i < keywords->size(); i++)
        {
            if (str == keywords[i])
                return true;
        }

        return false;
    }

    bool lexer::is_identifier(const std::string& str)
    {
        if (utils::is_empty(str))
            return false;

        for (int i = 0; i < str.size(); i++)
        {
            if (!isalpha(str[i]) || str[i] == '_')
                return false;
        }

        return true;
    }

    bool lexer::is_int(const std::string& str)
    {
        if (utils::is_empty(str))
            return false;

        for (int i = 0; i < str.size(); i++)
        {
            if (!isdigit(str[i]))
                return false;
        }

        return true;
    }

    bool lexer::is_float(const std::string& str)
    {
        if (utils::is_empty(str))
            return false;

        int dot_count = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (isdigit(str[i]))
                continue;

            else if (str[i] == '.' && dot_count < 2)
            {
                dot_count++;
                continue;
            }

            return false;
        }

        return true;
    }

    bool lexer::is_operator(const char& c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
               c == '=' || c == '<' || c == '>' ||
               c == '!' || c == '&' || c == '|';
    }

    bool lexer::is_symbol(const char& c)
    {
        return c == ':' || c == '.' || c == ',' || c == ';' ||
               c == '#' || c == '@';
    }

    bool lexer::is_paren(const char& c)
    {
        return c == '(' || c == ')' || c == '[' || c == ']';
    }
}
