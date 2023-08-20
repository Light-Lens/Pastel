#pragma once

namespace Pastel
{
    class parser
    {
    public:
        std::string current_line;
        int current_line_no;

    public:
        void translator(const std::vector<Tokens::Token>& tokens);
    };
}
