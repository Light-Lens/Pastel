#pragma once

namespace console
{
    WORD get_console_color();
    void reset_console_color();
    void set_console_color(WORD color);
}

namespace Pastel
{
    namespace errors
    {
        void errors(const std::string& name_of_error, const std::string& details, const int& line_no);
        void throw_error(const std::string& details, const int& line_no=-1, const std::string& name_of_error="");
        void runtime(const std::string& details, const int& line_no);
        void lexical(const std::string& details, const int& line_no);
        void open_file(const std::string& filename);
    }
}
