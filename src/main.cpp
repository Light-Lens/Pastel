#include <iostream>
#include <fstream>
#include <vector>

#include "errors.h"
#include "collections.h"
#include "manager.h"

using namespace std;

void run(const string& current_line, int current_line_no)
{
    // code here.
}

int main(int argc, char const *argv[])
{
    vector<string> cmd_line_args = manager::cmd_line_args_parser(argc, argv);
    fstream file;

    string current_line;
    int current_line_no = 0;

    if (cmd_line_args.empty())
    {
        console::set_console_color(9);
        cout << "Pastel 2023 [Version 0.1]";
        console::reset_console_color();

        cout << "\n> ";
        while (getline(cin, current_line))
        {
            run(current_line, current_line_no++);
            cout << "\n> ";
        }
    }

    else if (strings::endswith(cmd_line_args[0], ".pastel"))
    {
        file.open(cmd_line_args[0]);
        if (!file)
            errors::open_file(cmd_line_args[0]);

        while (getline(file, current_line))
            run(current_line, current_line_no++);

        file.close();
    }

    else
        errors::file_format(cmd_line_args[0]);

    return 0;
}
