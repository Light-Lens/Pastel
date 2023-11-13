#include "pastelpch.h"
#include "errors.h"
#include "utils/Utils/strings.h"
#include "utils/Console/console.h"

namespace Pastel
{
    namespace errors
    {
        void errors(const std::string& details, const int& line_no, const std::string& name_of_error)
        {
            WORD color = console::get_console_color();

            console::set_console_color(0xF);
            std::cout << "at line " + std::to_string(line_no) + ": ";

            console::set_console_color(12);
            std::cout << name_of_error << " error:\n";

            console::set_console_color(color);
            std::cout << details << std::endl;
        }

        void errors(const std::string& details, const std::string& name_of_error)
        {
            WORD color = console::get_console_color();

            console::set_console_color(12);
            std::cout << name_of_error << " error:\n";

            console::set_console_color(color);
            std::cout << details << std::endl;
        }

        void errors(const std::string& details, const int& line_no)
        {
            WORD color = console::get_console_color();

            console::set_console_color(0xF);
            std::cout << "at line " + std::to_string(line_no) + ": ";

            console::set_console_color(12);
            std::cout << "error:\n";

            console::set_console_color(color);
            std::cout << details << std::endl;
        }

        void errors(const std::string& details)
        {
            WORD color = console::get_console_color();

            console::set_console_color(12);
            std::cout << "error:\n";

            console::set_console_color(color);
            std::cout << details << std::endl;
        }



        void throw_error(const std::string& name_of_error, const std::string& line, const std::string& details, const int& line_no)
        {
            WORD color = console::get_console_color();

            errors(details, line_no, name_of_error);

            console::set_console_color(12);
            std::cout << "-> ";
            console::set_console_color(color);
            std::cout << line << std::endl;

            exit(0);
        }

        void runtime(const std::string& details, const std::string& line, const int& line_no)
        {
            throw_error("runtime", line, details, line_no);
        }

        void lexical(const std::string& details, const std::string& line, const int& line_no)
        {
            throw_error("lexical", line, details, line_no);
        }

        void fatal(const std::string& details, const std::string& line, const int& line_no)
        {
            throw_error("fatal", line, details, line_no);
        }

        // Cannot open file.
        void open_file(const std::string& filename)
        {
            errors(filename + ": No such file or directory.");
            exit(0);
        }
    }
}
