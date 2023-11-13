#include "pastelpch.h"
#include "terminalcolor.h"
#include "console.h"

namespace utils
{
    /**
    * Print a colored message.
    * 
    * @param message String that is to be printed in colors.
    * @param color The name of the color to be printed. https://stackoverflow.com/a/4053879/18121288
    * @param is_newline Creates a newline or doesn't (default=true).
    * @return void
    */
    void terminalcolor::print(const std::string& message, const WORD& color, const bool& is_newline=true)
    {
        WORD default_color = console::get_console_color();
        console::set_console_color(color);

        std::cout << message;

        if (is_newline)
            std::cout << std::endl;

        console::set_console_color(default_color);
    }
}
