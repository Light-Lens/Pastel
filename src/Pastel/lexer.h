#pragma once

#include "tokens.h"

namespace Pastel
{
    class lexer
    {
    private:
        int current_line_no = 1;
        std::string current_line;

    public:
        lexer(std::fstream& file);

    private:
        std::vector<Tokens::Token> tokenizer();
        bool is_keyword(const std::string& str);
        bool is_identifier(const std::string& str);
        bool is_int(const std::string& str);
        bool is_float(const std::string& str);
        bool is_operator(const char& c);
        bool is_symbol(const char& c);
        bool is_paren(const char& c);
    };
}
