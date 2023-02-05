#pragma once
#include <iostream>

namespace strings
{
    bool startswith(const std::string& sentence, const std::string& what_to_find);
    bool endswith(const std::string& sentence, const std::string& what_to_find);
    bool find(const std::string& sentence, const std::string& what_to_find);
    std::string trim(const std::string& sentence);
    bool iseven(const int& number);
}
