#include <iostream>
#include "strings.h"

using namespace std;

namespace strings
{
    bool startswith(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.find(what_to_find) == 0;
    }

    bool endswith(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.length() >= what_to_find.length() &&
            sentence.compare(sentence.length() - what_to_find.length(), what_to_find.length(), what_to_find) == 0;
    }

    bool find(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.find(what_to_find) != std::string::npos;
    }

    std::string trim(const std::string& sentence)
    {
        const std::string Whitespace = " \t";
        auto strBegin = sentence.find_first_not_of(Whitespace);
        if (strBegin == std::string::npos) return "";

        auto strEnd = sentence.find_last_not_of(Whitespace);
        auto strRange = strEnd - strBegin + 1;

        return sentence.substr(strBegin, strRange);
    }

    bool iseven(const int& number)
    {
        return number % 2 == 0;
    }
}
