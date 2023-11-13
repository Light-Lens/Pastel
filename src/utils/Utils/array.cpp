#include "pastelpch.h"
#include "array.h"

namespace utils
{
    std::vector<std::string> array::reduce(const std::vector<std::string>& arr)
    {
        std::vector<std::string> result;
        std::copy_if(arr.begin(), arr.end(), std::back_inserter(result), [](const std::string& str) { return !str.empty(); });

        return result;
    }
}
