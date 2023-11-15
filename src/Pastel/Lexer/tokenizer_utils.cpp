#include "pastelpch.h"
#include "lexer.h"

#include "utils/Utils/strings.h"

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
            if (!isalpha(str[i]) || str[i] == '_')
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
            if (!isdigit(str[i]))
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
