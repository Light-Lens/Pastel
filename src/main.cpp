#include "pastelpch.h"
#include "utils/strings.h"
#include "utils/fileio.h"

void init_folders()
{
    FileIO::create_dir(".pastel");
    FileIO::create_dir(".pastel/vendor");
    FileIO::create_dir(".pastel/scripts");
    FileIO::create_dir(".pastel/cache");
}

int main(int argc, char const *argv[])
{
    std::string name = argv[1];
    if (argc > 1)
    {
        if (Strings::lowercase(name) == "init")
            init_folders();

        // if (endswith(name, ".pastel"))
        //     std::cout << name << std::endl;
    }

    return 0;
}
