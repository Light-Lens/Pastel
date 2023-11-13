#pragma once

namespace utils
{
    class strings
    {
        public:
            static bool is_empty(const std::string& str);
            static bool endswith(const std::string& sentence, const std::string& what_to_find);
            static std::string lowercase(std::string str);
            static std::string replace_last(std::string str, const std::string& str_to_be_replaced, const std::string& str_to_be_replaced_with);
            static std::string join(const std::string& separator, const std::vector<std::string>& arr);
    };
}
