#include "../pastelpch.h"
#include "tokens.h"

namespace Pastel
{
    namespace tokens
    {
        enum token_type
        {
            EMPTY = 0,
            UNKNOWN,
            COMMENT,
            SYMBOL,
            STRING,
            INT,
            FLOAT,
            CHAR,
            KEYWORD,
            IDENTIFIER,
            OPERATOR,
            PAREN,
        };

        struct token
        {
            token_type type;
            std::string name;
        };

        std::string keywords[] = {
            "include",
            "let",
            "auto",
            "const",
            "var",
            "str",
            "int",
            "float",
            "bool",
            "double",
            "return",
            "fun",
            "void",
            "struct",
            "class",
            "namespace",
            "enum",
            "switch",
            "case",
            "if",
            "elif",
            "else"
        };
    }
}
