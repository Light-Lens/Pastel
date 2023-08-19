#include "pastelpch.h"
#include "utils/strings.h"
#include "utils/fileio.h"
#include "Pastel/errors.h"
#include "Pastel/lexer.h"

void init_folders()
{
    utils::create_dir(".pastel");
    utils::create_dir(".pastel/vendor");
    utils::create_dir(".pastel/scripts");
    utils::create_dir(".pastel/cache");
}

int main(int argc, char const *argv[])
{
    std::string arg = argv[1];
    if (argc > 1)
    {
        init_folders();
        if (utils::lowercase(arg) == "install")
        {
            // install any libraries into the vendor folder to be used by c++
            // for eg, SDL2 or spdlog, it will automatically be included during compilation
            std::string lib_name = argv[2];
            utils::copy_dir(lib_name, ".pastel/vendor/" + lib_name);
        }

        else if (utils::endswith(arg, ".pastel"))
        {
            // Rename arg to filename
            std::string& filename = arg;
            std::fstream file;

            // Open the file
            file.open(filename);

            // Interpret the file line by line
            if (file)
                Pastel::lexer lx(file);

            // Throw error if the file can't be opened.
            else
                Pastel::errors::open_file(filename);

            // Close the file
            file.close();
        }
    }

    return 0;
}
