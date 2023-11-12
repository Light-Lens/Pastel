#include "pastelpch.h"
#include "argparse.h"

argparse::argparse(const std::string& name, const std::string& description, const std::function<void(std::string)>& error_func)
{
    this->name = name;
    this->description = description;
    this->error_func = error_func;
}

void argparse::add(const std::vector<std::string>& cmd_names, const std::string& help_message, const std::string& default_value, const bool& is_flag, const bool& required)
{
    this->arguments.emplace_back(cmd_names, help_message, default_value, is_flag, required);
}
