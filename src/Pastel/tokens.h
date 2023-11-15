#pragma once

namespace Pastel
{
    enum token_type
    {
        UNKNOWN = 0,
        COMMENT,
        STRING,
        INT,
        FLOAT,
        CHAR,
        KEYWORD,
        IDENTIFIER,
        LPAREN,
        RPAREN,
        LBRACE,
        RBRACE,
        LBRACKET,
        RBRACKET,
        COLON,
        SEMICOLON,
        DOT,
        COMMA,
        ATTHERATE,
        PLUS,
        MINUS,
        MUL,
        DIV,
        MOD,
        EQUAL,
        GREATERTHAN,
        SMALLERTHAN,
        NOT,
        AND,
        OR,
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
