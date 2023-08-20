#pragma once

namespace Pastel
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

    extern const std::string keywords[];
}
