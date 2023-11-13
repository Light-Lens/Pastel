#pragma once

namespace utils
{
    class terminalcolor
    {
        public:
            static void print(const std::string& message, const WORD& color, const bool& is_newline=true);
    };
}
