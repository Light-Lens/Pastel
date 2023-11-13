#pragma once

#include "Pastel/tokens.h"

namespace Pastel
{
    class lexer
    {
    public:
        std::vector< std::vector<token> > tokenized_code;

    private:
        std::string current_line;
        int current_line_no;

    public:
        lexer(const std::vector<std::string>& code);

    private:
        std::vector<token> tokenizer();
        bool is_keyword(const std::string& str);
        bool is_identifier(const std::string& str);
        bool is_int(const std::string& str);
        bool is_float(const std::string& str);
        bool is_operator(const char& c);
        bool is_symbol(const char& c);
        bool is_paren(const char& c);
    };
}
