#pragma once

namespace Pastel
{
    class Tokens
    {
    public:
        enum TokenType
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

        struct Token
        {
            TokenType type;
            std::string name;
        };

        std::string keywords[22] = {
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
    };
}
