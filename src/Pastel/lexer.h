#pragma once

namespace Pastel
{
    class lexer
    {
    public:
        // lexer(const std::string& current_line, const int& current_line_no);
        lexer(const std::fstream& filename);

    private:
        std::string current_line;
        int current_line_no;
    };
}
