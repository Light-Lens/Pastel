#pragma once
#include <iostream>
#include <vector>

#include <windows.h>

// Manage Arguments, Packages and Comments
namespace manager
{
    std::vector<std::string> cmd_line_args_parser(int argc, char const *argv[]);
}

// Change the Color of the Current Line in Console.
namespace console
{
    void set_console_color(WORD color);
    void reset_console_color();
}
