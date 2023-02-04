#include <vector>
#include <windows.h>
#include "manager.h"

using namespace std;

namespace manager
{
    // Copy paste all command line arguments to an array except 'Glass.exe'.
    vector<string> cmd_line_args_parser(int argc, char const *argv[])
    {
        vector<string> cmd_line_args(argv, argv + argc);
        cmd_line_args.erase(cmd_line_args.begin());

        return cmd_line_args;
    }
}

namespace console
{
    // Set console color.
    void set_console_color(WORD Color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
    }

    // Reset console color.
    void reset_console_color()
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}
