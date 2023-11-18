#include "pastelpch.h"
#include "lexer.h"

#include "utils/Utils/strings.h"
#include "Pastel/Errors/errors.h"

namespace Pastel
{
    bool lexer::is_keyword(const std::string& str)
    {
        for (int i = 0; i < keywords.size(); i++)
        {
            if (str == keywords[i])
                return true;
        }

        return false;
    }

    bool lexer::is_identifier(const std::string& str)
    {
        if (utils::strings::is_empty(str))
            return false;

        for (int i = 0; i < str.size(); i++)
        {
            if (!isdigit(str[i]) && !isalpha(str[i]) && str[i] != '_')
                return false;
        }

        return true;
    }

    bool lexer::is_int(const std::string& str)
    {
        if (utils::strings::is_empty(str))
            return false;

        for (int i = 0; i < str.size(); i++)
        {
            if (i > 0 && !isdigit(str[i]) && str[i] != '.')
                Pastel::errors::lexical("expected an identifier before numeric constant", this->current_line, this->current_line_no);

            else if (!isdigit(str[i]))
                return false;
        }

        return true;
    }

    bool lexer::is_float(const std::string& str)
    {
        if (utils::strings::is_empty(str))
            return false;

        int dot_count = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (dot_count >= 2)
                Pastel::errors::lexical("too many decimal points in number", this->current_line, this->current_line_no);

            else if (str[i] == '.')
            {
                dot_count++;
                continue;
            }

            else if (i > 0 && !isdigit(str[i]) && str[i] != '.')
                Pastel::errors::lexical("expected an identifier before numeric constant", this->current_line, this->current_line_no);

            else if (!isdigit(str[i]))
                return false;
        }

        return true;
    }

    bool lexer::is_operator(const std::string& c)
    {
        return c == "+" || c == "-" || c == "*" || c == "/" || c == "%" ||
               c == "=" || c == "<" || c == ">" ||
               c == "!" || c == "&" || c == "|";
    }

    bool lexer::is_symbol(const std::string& c)
    {
        return c == ":" || c == "." || c == "," || c == ";" || c == "@" || c == "#";
    }

    bool lexer::is_paren(const std::string& c)
    {
        return c == "(" || c == ")" || c == "[" || c == "]" || c == "{" || c == "}";
    }

    token_type lexer::paren_token(const std::string& c)
    {
        if (c == "(")
            return token_type::LPAREN;

        else if (c == ")")
            return token_type::RPAREN;

        else if (c == "[")
            return token_type::LBRACKET;

        else if (c == "]")
            return token_type::RBRACKET;
        
        else if (c == "{")
            return token_type::LBRACE;

        else if (c == "}")
            return token_type::RBRACE;

        return token_type::UNKNOWN;
    }

    token_type lexer::symbol_token(const std::string& c)
    {
        if (c == ":")
            return token_type::COLON;

        else if (c == ";")
            return token_type::SEMICOLON;

        else if (c == ".")
            return token_type::DOT;

        else if (c == ",")
            return token_type::COMMA;

        else if (c == "@")
            return token_type::ATTHERATE;

        else if (c == "#")
            return token_type::HASHTAG;

        return token_type::UNKNOWN;
    }

    token_type lexer::operator_token(const std::string& c)
    {
        if (c == "+")
            return token_type::PLUS;

        else if (c == "-")
            return token_type::MINUS;

        else if (c == "*")
            return token_type::MUL;

        else if (c == "/")
            return token_type::DIV;

        else if (c == "%")
            return token_type::MOD;

        else if (c == "=")
            return token_type::EQUAL;

        else if (c == ">")
            return token_type::GREATERTHAN;

        else if (c == "<")
            return token_type::SMALLERTHAN;

        else if (c == "!")
            return token_type::NOT;

        else if (c == "&")
            return token_type::AND;

        else if (c == "|")
            return token_type::OR;

        return token_type::UNKNOWN;
    }
}
