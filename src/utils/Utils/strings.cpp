#include "pastelpch.h"
#include "strings.h"

namespace utils
{
    bool is_empty(const std::string& str)
    {
        return all_of(str.begin(), str.end(), ::isspace) || str.empty();
    }

    bool endswith(const std::string& sentence, const std::string& what_to_find)
    {
        return sentence.length() >= what_to_find.length() &&
            sentence.compare(sentence.length() - what_to_find.length(), what_to_find.length(), what_to_find) == 0;
    }

    std::string lowercase(std::string str)
    {
        for (char& c : str)
            c = std::tolower(c);

        return str;
    }

    std::string replace_last(std::string str, const std::string& str_to_be_replaced, const std::string& str_to_be_replaced_with)
    {
        size_t pos = str.rfind(str_to_be_replaced);  // Find the last occurrence of the search string
        if (pos != std::string::npos)
            str.replace(pos, str_to_be_replaced.length(), str_to_be_replaced_with);  // Replace the found occurrence

        return str;
    }
}
