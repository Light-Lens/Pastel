#pragma once

namespace console
{
    WORD get_console_color();
    void reset_console_color();
    void set_console_color(WORD color);
}

namespace Pastel
{
    namespace errors
    {
        void errors(const std::string& details);
        void throw_error(const std::string& details);
        void runtime(const std::string& details);
        void open_file(const std::string& filename);
    }
}
