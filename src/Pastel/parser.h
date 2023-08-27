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
        parser(const std::vector< std::vector<token> >& tokenized_code, const std::vector<std::string>& original_lines);

    private:
        void translator(const std::vector<token>& tokens);
        void handle_includes(const std::vector<token>& tok, int& start_index);
        bool contains_keywords(const std::vector<token>& tokens, const std::vector<std::string>& list_of_keywords);
    };
}
