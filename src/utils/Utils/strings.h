#pragma once

namespace utils
{
    class strings
    {
        public:
            static bool is_empty(const std::string& str);
            static bool endswith(const std::string& str, const std::string& suffix);
            static std::string lowercase(std::string str);
            static std::string replace_last(std::string str, const std::string& old_substr, const std::string& new_substr);
            static std::string join(const std::string& separator, const std::vector<std::string>& arr);
    };
}
