#include "pastelpch.h"
#include "lexer.h"

#include "utils/Utils/strings.h"
#include "Pastel/Errors/errors.h"

namespace Pastel
{
    std::vector<token> lexer::tokenizer()
    {
        std::vector<token> tokens;
        std::string tok;

        for (int i = 0; i < this->current_line.size(); i++)
        {
            tok += this->current_line[i];

            if (utils::strings::is_empty(tok))
                tok.clear();

            // COMMENT
            else if (this->current_line[i] == '/' && current_line[i+1] == '/')
                break;

            else if (this->is_paren(tok))
            {
                tokens.push_back({paren_token(tok), tok});
                tok.clear();
            }

            else if (this->is_symbol(tok))
            {
                tokens.push_back({this->symbol_token(tok), tok});
                tok.clear();
            }

            else if (this->is_operator(tok))
            {
                tokens.push_back({this->operator_token(tok), tok});
                tok.clear();
            }

            else if (is_float(tok))
            {
                i++;
                while (i < this->current_line.size() && this->is_float(std::string(1, this->current_line[i])))
                {
                    tok += this->current_line[i];
                    i++;
                }

                i--;

                if (this->is_int(tok))
                    tokens.push_back({token_type::INT, tok});

                else if (this->is_float(tok))
                    tokens.push_back({token_type::FLOAT, tok});

                tok.clear();
            }

            else if (this->is_identifier(tok))
            {
                i++;
                while (i < this->current_line.size() && this->is_identifier(std::string(1, this->current_line[i])) && this->current_line[i] != ' ')
                {
                    tok += this->current_line[i];
                    i++;
                }

                i--;

                if (this->is_keyword(tok))
                    tokens.push_back({token_type::KEYWORD, tok});

                else if (this->is_identifier(tok))
                    tokens.push_back({token_type::IDENTIFIER, tok});

                tok.clear();
            }

            else if (tok == "'" || tok == "\"")
            {
                char str_char_symbol = tok[0];

                i++;
                if (i < this->current_line.size())
                {
                    while (i < this->current_line.size() && this->current_line[i] != str_char_symbol)
                    {
                        tok += this->current_line[i];
                        i++;
                    }
                    tok += this->current_line[i];

                    if (i >= this->current_line.size())
                    {
                        std::string error_detail = "missing terminating " + std::string(1, str_char_symbol) + " character";
                        errors::lexical(current_line, error_detail, current_line_no);
                    }
                }

                else
                {
                    std::string error_detail = "unexpected end of tokens after " + std::string(1, str_char_symbol);
                    errors::lexical(current_line, error_detail, current_line_no);
                }

                if (this->current_line[i] == '"')
                    tokens.push_back({token_type::STRING, tok});

                else if (this->current_line[i] == '\'')
                    tokens.push_back({token_type::CHAR, tok});

                tok.clear();
            }

            else
            {
                tokens.push_back({token_type::UNKNOWN, tok});
                tok.clear();
            }
        }

        return tokens;
    }
}
