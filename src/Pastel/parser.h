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

    private:
        void handle_comments(const token& tok);
        void handle_includes(const std::vector<token>& tok, const int& start_index);
        void handle_variables(const std::vector<token>& tok, const int& start_index);
    };
}
