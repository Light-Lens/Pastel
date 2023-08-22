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
            run(load_file(arg));
    }

    return 0;
}
