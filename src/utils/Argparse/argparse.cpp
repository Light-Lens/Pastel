#include "pastelpch.h"
#include "argparse.h"

argparse::argparse(const std::string& name, const std::string& description)
{
    this->name = name;
    this->description = description;
}

void argparse::add(const std::vector<std::string>& cmd_names, const std::string& help_message, const std::string& default_value, const bool& is_flag, const bool& required)
{
}
