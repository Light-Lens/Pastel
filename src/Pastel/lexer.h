#pragma once

namespace Pastel
{
    class lexer
    {
    public:
        struct Token;

    private:
        std::string current_line;
        int current_line_no = 1;

    public:
        // lexer(const std::string& current_line, const int& current_line_no);
        lexer(std::fstream& file);

    private:
        std::vector<lexer::Token> tokenizer();
    };
}
