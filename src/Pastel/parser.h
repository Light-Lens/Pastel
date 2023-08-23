#pragma once

namespace Pastel
{
    class parser
    {
    private:
        int current_line_no = 1;
        std::string current_line;
        std::vector< std::vector<std::string> > translation;

    public:
        parser(const std::vector< std::vector<token> >& tokenized_code);

    private:
        void translator(const std::vector<token>& tokens);
        void handle_comments(const token& tok);
        void handle_includes(const std::vector<token>& tok, const int& start_index);
        bool contains_keywords(const std::vector<token>& tokens, const std::vector<std::string>& list_of_keywords);
    };
}
