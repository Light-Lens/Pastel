#pragma once

namespace Pastel
{
    enum token_type
    {
        UNKNOWN = 0,
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
