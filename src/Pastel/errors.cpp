#include "../pastelpch.h"
#include "../utils/strings.h"
#include "errors.h"

namespace console
{
    // Get console color.
    WORD get_console_color()
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hOut, &csbi);

        return csbi.wAttributes;
    }

    // Reset console color.
    void reset_console_color()
    {
        set_console_color(7);
    }

    // Set console color.
    void set_console_color(WORD color)
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hOut, color);
    }
}

namespace Pastel
{
    namespace errors
    {
        void errors(const std::string& details, const int& line_no, const std::string& name_of_error)
        {
            WORD color = console::get_console_color();


            if (line_no >= 0)
            {
                console::set_console_color(0xF);
                std::cout << "at line " + std::to_string(line_no) + ": ";
            }


            console::set_console_color(12);
            if (!utils::is_empty(name_of_error))
                std::cout << name_of_error << " ";

            std::cout << "error:\n";


            console::set_console_color(color);
            std::cout << details << std::endl;
        }

        void throw_error(const std::string& name_of_error, const std::string& line, const std::string& details, const int& line_no)
        {
            WORD color = console::get_console_color();

            errors(details, line_no, name_of_error);

            console::set_console_color(12);
            std::cout << "-> " << line << std::endl;
            console::set_console_color(color);

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
            errors(filename + ": No such file or directory.", -1, "");
            exit(0);
        }
    }
}
