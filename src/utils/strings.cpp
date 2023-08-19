#include "../pastelpch.h"
#include "strings.h"

namespace utils
{
    bool endswith(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.length() >= what_to_find.length() &&
            sentence.compare(sentence.length() - what_to_find.length(), what_to_find.length(), what_to_find) == 0;
    }

    std::string lowercase(std::string str)
    {
        for (char& c : str)
        {
            c = std::tolower(c);
        }

        return str;
    }
}
