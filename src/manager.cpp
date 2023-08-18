#include "manager.h"

namespace manager
{
    std::vector<std::string> arguments(int argc, char *argv[])
    {
        std::vector<std::string> cmd_line_args(argv, argv + argc);
        cmd_line_args.erase(cmd_line_args.begin());

        return cmd_line_args;
    }
}
