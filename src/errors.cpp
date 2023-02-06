#include <iostream>

#include "errors.h"
#include "collections.h"

using namespace std;

namespace errors
{
    void errors(const string& details)
    {
        WORD color = console::get_console_color();
        console::set_console_color(12);

        cout << details << endl;

        console::set_console_color(color);
    }

    void throw_error(const string& details)
    {
        errors(details);
        exit(0);
    }

    void runtime(const string& details)
    {
        throw_error(details);
    }

    // Cannot open file.
    void open_file(const string& filename)
    {
        throw_error(filename + ": No such file or directory.");
    }

    // Unrecognized file format.
    void file_format(const string& filename)
    {
        throw_error(filename + ": File format not recognized");
    }
}
