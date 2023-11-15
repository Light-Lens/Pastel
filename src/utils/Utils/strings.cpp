#include "pastelpch.h"
#include "strings.h"

namespace utils
{
    bool strings::is_empty(const std::string& str)
    {
        return all_of(str.begin(), str.end(), ::isspace) || str.empty();
    }

    bool strings::endswith(const std::string& str, const std::string& suffix)
    {
        return str.length() >= suffix.length() &&
            str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
    }

    std::string strings::lowercase(std::string str)
    {
        for (char& c : str)
            c = std::tolower(c);

        return str;
    }

    std::string strings::replace_last(std::string str, const std::string& old_substr, const std::string& new_substr)
    {
        size_t pos = str.rfind(old_substr);  // Find the last occurrence of the search string
        if (pos != std::string::npos)
            str.replace(pos, old_substr.length(), new_substr);  // Replace the found occurrence

        return str;
    }

    std::string strings::join(const std::string& separator, const std::vector<std::string>& arr)
    {
        std::string str = "";
        for (int i = 0; i < arr.size(); ++i)
        {
            str += arr[i];
            if (i < arr.size() - 1)
                str += separator;
        }

        return str;
    }
}
