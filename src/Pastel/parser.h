#pragma once

namespace Pastel
{
    class parser
    {
    public:
        std::string current_line;
        int current_line_no;

    private:
        std::vector<std::string> translation;

    public:
        void translator(const std::vector<token>& tokens);
    };
}
