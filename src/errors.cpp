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

    // Cannot open file.
    void open_file(const string& filename)
    {
        errors(filename + ": No such file or directory.");
        exit(0);
    }

    // Unrecognized file format.
    void file_format(const string& filename)
    {
        errors(filename + ": File format not recognized");
        exit(0);
    }
}
