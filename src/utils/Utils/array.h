#pragma once

namespace utils
{
    class array
    {
        public:
            static std::vector<std::string> reduce(const std::vector<std::string>& arr);
            static bool is_empty(const std::vector<std::string>& arr);
    };
}
