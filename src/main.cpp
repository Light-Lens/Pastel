#include "pastelpch.h"
#include "pastel.h"
#include "utils/Utils/math.h"
#include "utils/Argparse/argparse.h"

void unrecognized_argument_error(const std::string& err)
{
    Pastel::errors::errors(err, "Unrecognized argument");
}

int main(int argc, char const *argv[])
{
    utils::argparse parser = utils::argparse("Pastel", "A programming language", unrecognized_argument_error);
    parser.add({"-h", "--help", "/?", "-?"}, "Show help message", "", true, false);
    parser.add({"--init"}, "Initialize a Pastel project", "", true, false);
    parser.add({"-i", "--install"}, "Install a library", "", false, false);

    std::vector<std::string> args(argv, argv + argc);
    args.erase(args.begin());

    std::vector<utils::argparse::parsed_argument> parsed_args = parser.parse(args);

    for (const auto& arg : parsed_args)
    {
        if (std::find(arg.names.begin(), arg.names.end(), "-h") != arg.names.end())
        {
            // print help message.
            return 0;
        }

        else if (std::find(arg.names.begin(), arg.names.end(), "--init") != arg.names.end())
            init_folders();

        else if (std::find(arg.names.begin(), arg.names.end(), "--init") != arg.names.end())
            install_lib(arg.value);

        else if (utils::strings::endswith(arg.names[0], ".pastel"))
            run(load_file(arg.names[0]));

        else
        {
            unrecognized_argument_error(arg.names[0] + ": Please type 'pastel help' for more information");
            return 0;
        }
    }

    return 0;
}
