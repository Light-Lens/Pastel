#pragma once

#include "strings/strings.h"

void run(int argc, char const *argv[])
{
    std::string name = argv[1];
    if (argc > 1)
    {
        // if (endswith(name, ".pastel"))
        //     std::cout << name << std::endl;

        if (lowercase(name) == "init")
        {
            std::cout << name << std::endl;
        }
    }
}
