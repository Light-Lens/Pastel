#include <iostream>
#include <vector>

#include <windows.h>
#include "collections.h"

using namespace std;

namespace strings
{
    bool startswith(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.find(what_to_find) == 0;
    }

    bool endswith(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.length() >= what_to_find.length() &&
            sentence.compare(sentence.length() - what_to_find.length(), what_to_find.length(), what_to_find) == 0;
    }

    bool find(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.find(what_to_find) != std::string::npos;
    }

    std::string trim(const std::string& sentence)
    {
        const std::string Whitespace = " \t";
        auto strBegin = sentence.find_first_not_of(Whitespace);
        if (strBegin == std::string::npos) return "";

        auto strEnd = sentence.find_last_not_of(Whitespace);
        auto strRange = strEnd - strBegin + 1;

        return sentence.substr(strBegin, strRange);
    }

    bool iseven(const int& number)
    {
        return number % 2 == 0;
    }
}

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
