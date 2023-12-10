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

            std::vector<token> toks = this->tokenizer();

            this->tokenized_code.insert(this->tokenized_code.end(), toks.begin(), toks.end());
        }

        for (const auto& i : this->tokenized_code)
        {
            if (i.type == token_type::EOL)
                std::cout << "END OF LINE\n";

            else
                std::cout << "NAME: " << i.name << ", TYPE: " << i.type << std::endl;
        }
    }
}
