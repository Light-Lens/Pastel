#pragma once

namespace Pastel
{
    class lexer
    {
    private:
        struct Token;
        int current_line_no = 1;
        std::string current_line;
        static std::string keywords[];

    public:
        lexer(std::fstream& file);

    private:
        std::vector<lexer::Token> tokenizer();
        bool is_keyword(const std::string& str);
        bool is_identifier(const std::string& str);
        bool is_int(const std::string& str);
        bool is_float(const std::string& str);
        bool is_operator(const char& c);
        bool is_symbol(const char& c);
        bool is_paren(const char& c);
        void parse_string(const std::string& current_line, std::string& tok, const char& str_symbol, int& i);
    };
}
