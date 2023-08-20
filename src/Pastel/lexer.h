#pragma once

#include "tokens.h"

namespace Pastel
{
    class lexer
    {
    public:
        std::string current_line;
        int current_line_no;

    public:
        std::vector<token> tokenizer();

    private:
        bool is_keyword(const std::string& str);
        bool is_identifier(const std::string& str);
        bool is_int(const std::string& str);
        bool is_float(const std::string& str);
        bool is_operator(const char& c);
        bool is_symbol(const char& c);
        bool is_paren(const char& c);
    };
}
