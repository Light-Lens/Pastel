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

    extern const std::vector<std::string> include_keywords;
    extern const std::vector<std::string> variable_keywords;
    extern const std::vector<std::string> boolean_keywords;
    extern const std::vector<std::string> container_keywords;
    extern const std::vector<std::string> control_flow_keywords;

    extern const std::vector<std::string> keywords;
}
