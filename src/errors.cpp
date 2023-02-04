#include <iostream>

#include "errors.h"
#include "manager.h"

using namespace std;

namespace errors
{
    // Unrecognized file format.
    void file_format(std::string filename)
    {
        console::set_console_color(12);
        cout << "Error!" << endl;
        cout << filename << ": File not recognized: File format not recognized" << endl;

        console::reset_console_color();
        exit(0);
    }

    // Cannot open file.
    void open_file(string filename)
    {
        console::set_console_color(12);
        cout << "Error!" << endl;
        cout << filename << ": No such file or directory." << endl;

        console::reset_console_color();
        exit(0);
    }
}
