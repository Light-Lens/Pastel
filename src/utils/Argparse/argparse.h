#pragma once

class argparse
{
private:
    std::string name = "";
    std::string description = "";

public:
    struct argparse
    {
        /* data */
    };
    

public:
    argparse(const std::string& name, const std::string& description);
    void add(const std::vector<std::string>& cmd_names, const std::string& help_message, const std::string& default_value = "", const bool& is_flag = false, const bool& required = false);
};
