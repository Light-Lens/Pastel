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
            this->current_line = code[i];
            this->current_line_no = i+1;
            this->tokenized_code.push_back(tokenizer());
        }
    }
}
