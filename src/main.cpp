#include <iostream>
#include <fstream>
#include <vector>

#include "errors.h"
#include "strings.h"
#include "manager.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> cmd_line_args = manager::cmd_line_args_parser(argc, argv); // Get all command line args
    fstream file; // Create an empty file stream.

    string current_line;

    if (!strings::endswith(cmd_line_args[0], ".pastel"))
        errors::file_format(cmd_line_args[0]);

    else
    {
        // Check if file opens properly.
        file.open(cmd_line_args[0]);
        if (!file)
            errors::open_file(cmd_line_args[0]);

        else
        {
            // Run until the file is reached it's end
            while (getline(file, current_line))
                cout << current_line << endl;
        }

        file.close(); // Close the file.
    }

    return 0;
}
