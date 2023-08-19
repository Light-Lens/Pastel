#include "../pastelpch.h"
#include "lexer.h"

namespace Pastel
{
    // lexer::lexer(const std::string& current_line, const int& current_line_no)
    lexer::lexer(const std::fstream& file)
    {
        while (std::getline(file, current_line))
            std::cout << current_line_no << ". " << current_line << endl;
            // tokenizer(current_line, current_line_no++);
    }
}
