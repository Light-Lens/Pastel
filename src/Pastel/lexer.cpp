#include "../pastelpch.h"
#include "lexer.h"

namespace Pastel
{
    // lexer::lexer(const std::string& current_line, const int& current_line_no)
    lexer::lexer(std::fstream& file)
    {
        while (std::getline(file, current_line))
        {
            std::cout << current_line_no << ". " << current_line << std::endl;
            ++current_line_no;
            // tokenizer(current_line, current_line_no++);
        }
    }
}
