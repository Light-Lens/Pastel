#include "pastelpch.h"
#include "lexer.h"

#include "utils/Utils/strings.h"
#include "Pastel/Errors/errors.h"

namespace Pastel
{
    lexer::lexer(const std::vector<std::string>& code)
    {
        for (int i = 0; i < code.size(); i++)
        {
            current_line = code[i];
            current_line_no = i+1;
            tokenized_code.push_back(tokenizer());
        }
    }
}
