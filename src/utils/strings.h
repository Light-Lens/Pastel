#pragma once

namespace utils
{
    bool is_empty(const std::string& str);
    bool endswith(const std::string& sentence, const std::string& what_to_find);
    std::string lowercase(std::string str);
    std::string replace_last(std::string str, const std::string& str_to_be_replaced, const std::string& str_to_be_replaced_with);
}
