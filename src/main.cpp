#include "pastelpch.h"
#include "pastel.h"

int main(int argc, char const *argv[])
{
    std::string arg = utils::lowercase(argv[1]);
    if (argc > 1)
    {
        init_folders();
        if (arg == "init")
            init_folders();

        else if (arg == "install")
            install_lib(argv[2]);

        else if (utils::endswith(arg, ".pastel"))
        {
            std::fstream file;
            std::string& filename = arg; // rename arg to filename for better readability

            file.open(filename);

            // Interpret the file line by line
            // throw error if the file can't be opened.
            if (file) run(file);
            else Pastel::errors::open_file(filename);

            file.close();
        }
    }

    return 0;
}
