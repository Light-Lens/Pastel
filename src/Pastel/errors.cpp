#include "../pastelpch.h"
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
        void errors(const std::string& details)
        {
            WORD color = console::get_console_color();
            console::set_console_color(12);

            std::cout << details << std::endl;

            console::set_console_color(color);
        }

        void throw_error(const std::string& details)
        {
            errors(details);
            exit(0);
        }

        void runtime(const std::string& details)
        {
            throw_error(details);
        }

        // Cannot open file.
        void open_file(const std::string& filename)
        {
            throw_error(filename + ": No such file or directory.");
        }
    }
}