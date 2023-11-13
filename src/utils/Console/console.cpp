#include "pastelpch.h"
#include "console.h"

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
