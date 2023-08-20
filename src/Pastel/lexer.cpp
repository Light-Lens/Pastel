#include "../pastelpch.h"
#include "../utils/strings.h"
#include "errors.h"
#include "lexer.h"

namespace Pastel
{
    enum TokenType
    {
        EMPTY = 0,
        UNKNOWN,
        COMMENT,
        SYMBOL,
        STRING,
        INT,
        FLOAT,
        CHAR,
        KEYWORD,
        IDENTIFIER,
        OPERATOR,
        PAREN,
    };

    std::string lexer::keywords[] = {
        "include",
        "let"
    };

    struct lexer::Token
    {
        TokenType type;
        std::string name;
    };

    lexer::lexer(std::fstream& file)
    {
        while (std::getline(file, current_line))
        {
            std::vector<Token> tokens = tokenizer();
            for (int i = 0; i < tokens.size(); i++)
                std::cout << tokens[i].name;

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

            if (utils::is_empty(tok))
            {
                tokens.push_back({EMPTY, tok});
                tok.clear();
            }

            else if (current_line[i] == '/' && current_line[i+1] == '/')
            {
                i++;
                while (i < current_line.size())
                {
                    tok += current_line[i];
                    i++;
                }

                i--;

                tokens.push_back({COMMENT, tok});
                tok.clear();
                break;
            }

            else if (is_paren(current_line[i]) && tok.size() == sizeof(current_line[i]))
            {
                tokens.push_back({PAREN, tok});
                tok.clear();
            }

            else if (is_symbol(current_line[i]) && tok.size() == sizeof(current_line[i]))
            {
                tokens.push_back({SYMBOL, tok});
                tok.clear();
            }

            else if (is_operator(current_line[i]) && tok.size() == sizeof(current_line[i]))
            {
                tokens.push_back({OPERATOR, tok});
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
                    tokens.push_back({KEYWORD, tok});

                else
                    tokens.push_back({IDENTIFIER, tok});

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
                    tokens.push_back({INT, tok});

                else
                    tokens.push_back({FLOAT, tok});

                tok.clear();
            }

            else if (tok == "'" || tok == "\"")
            {
                // parse_string(current_line, tok, current_line[i], i);
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
                    tokens.push_back({STRING, tok});

                if (current_line[i] == '\'')
                {
                    if (tok.size() > 3)
                        errors::runtime("Multi-character literal at line " + std::to_string(current_line_no));

                    tokens.push_back({CHAR, tok});
                }

                tok.clear();
            }

            else
            {
                tokens.push_back({UNKNOWN, tok});
                tok.clear();
            }
        }

        return tokens;
    }

    bool lexer::is_keyword(const std::string& str)
    {
        for (int i = 0; i < (sizeof(keywords) / sizeof(keywords[0])); i++)
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

    void lexer::parse_string(const std::string& current_line, std::string& tok, const char& str_symbol, int& i)
    {
        i++;
        while (i < current_line.size() && current_line[i] != str_symbol)
        {
            // if (current_line[i] == '\\')
            // {
            //     i++;
            //     switch (current_line[i])
            //     {
            //     case '\\':
            //         tok += "\\";
            //         break;

            //     case '"':
            //         tok += "\"";
            //         break;

            //     case '\'':
            //         tok += "'";
            //         break;

            //     case 'n':
            //         tok += "\n";
            //         break;

            //     case '0':
            //         tok += "\0";
            //         break;

            //     case 't':
            //         tok += "\t";
            //         break;

            //     case 'r':
            //         tok += "\r";
            //         break;

            //     case 'b':
            //         tok += "\b";
            //         break;

            //     case 'a':
            //         tok += "\a";
            //         break;

            //     case 'f':
            //         tok += "\f";
            //         break;

            //     default:
            //         tok += "\\" + std::string(1, current_line[i]);
            //         break;
            //     }
            // }

            // else
            //     tok += current_line[i];

            tok += current_line[i];
            i++;
        }

        tok += current_line[i];
        if (i >= current_line.size())
            errors::runtime("Unterminated char at line " + std::to_string(current_line_no));
    }

    // std::vector<std::string> lexer::parser()
    // {
    //     std::string tok;
    //     std::vector<std::string> tokens;

    //     for (int i = 0; i < current_line.size(); i++)
    //     {
    //         tok += current_line[i];

    //         if (tok == "include")
    //             tok = "#include";
    //     }

    //     tokens.push_back(tok);
    //     return tokens;
    // }
}
