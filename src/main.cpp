#include "pastelpch.h"
#include "pastel.h"

int main(int argc, char const *argv[])
{
    std::string arg = utils::lowercase(argv[1]);
    if (argc > 1)
    {
        // init_folders();
        //TODO: Add a help message argument.
        if (arg == "help")
        {
            // print help message.
        }

        else if (arg == "init")
            init_folders();

        else if (arg == "install")
            install_lib(argv[2]);

        else if (utils::endswith(arg, ".pastel"))
            run(load_file(arg));

        else
            Pastel::errors::errors(arg + ": Please type 'pastel help' for more information", "Unrecognized argument");
    }

    return 0;
}
