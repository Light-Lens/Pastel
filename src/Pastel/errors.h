#pragma once

namespace Pastel
{
    namespace errors
    {
        void errors(const std::string& details, const int& line_no, const std::string& name_of_error);
        void errors(const std::string& details, const std::string& name_of_error);
        void errors(const std::string& details, const int& line_no);
        void errors(const std::string& details);

        void throw_error(const std::string& name_of_error, const std::string& line, const std::string& details, const int& line_no);
        void runtime(const std::string& details, const std::string& line, const int& line_no);
        void lexical(const std::string& details, const std::string& line, const int& line_no);
        void fatal(const std::string& details, const std::string& line, const int& line_no);
        void open_file(const std::string& filename);
    }
}
