#pragma once
#include <iostream>
#include <vector>

#include <windows.h>

namespace strings
{
    std::string trim(const std::string& sentence);
    bool startswith(const std::string& sentence, const std::string& what_to_find);
    bool endswith(const std::string& sentence, const std::string& what_to_find);
    bool find(const std::string& sentence, const std::string& what_to_find);
    bool isEven(const int& number);
    bool isEmpty(const std::string& str);
}

// Manage Arguments, Packages and Comments
namespace manager
{
    std::vector<std::string> cmd_line_args_parser(int argc, char const *argv[]);
}

// Change the Color of the Current Line in Console.
namespace console
{
    WORD get_console_color();
    void reset_console_color();
    void set_console_color(WORD color);
}
