#pragma once
#include <iostream>

namespace errors
{
    void errors(const std::string& details);
    void throw_error(const std::string& details);
    void runtime(const std::string& details);
    void open_file(const std::string& filename);
    void file_format(const std::string& filename);
}
