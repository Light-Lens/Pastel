#pragma once

namespace Pastel
{
    class lexer
    {
    private:
        struct Token;
        std::string current_line;
        int current_line_no = 1;

    public:
        lexer(std::fstream& file);

    private:
        std::vector<lexer::Token> tokenizer();
        bool is_identifier(const std::string& str);
        bool is_int(const std::string& str);
        bool is_float(const std::string& str);
        bool is_operator(const char& c);
        bool is_symbol(const std::string& str);
        void parse_string(const std::string& current_line, std::string& tok, const char& str_symbol, int& i);
    };
}
