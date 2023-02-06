#pragma once
#include <iostream>

class lexer
{
public:
    lexer(const std::string& current_line, int current_line_no);

private:
    void Tokenizer();
    bool isKeyword(const std::string &str);
    bool isInt(const std::string& str);
    bool isFloat(const std::string& str);

private:
    struct Token;

    static int line_no;
    static std::string original_line;
    static std::string keywords[];

    enum TokenType
    {
        INT,
        FLOAT,
        DOT,
        STRING,
        SEMICOLON,
        IDENTIFIER,
        KEYWORD,
        PLUS,
        MINUS,
        MUL,
        DIV,
        LPAREN,
        RPAREN,
        END
    };
};
