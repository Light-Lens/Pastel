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
    bool isIdentifier(const std::string& str);

private:
    struct Token;

    static int line_no;
    static std::string original_line;
    static std::string keywords[];

    enum TokenType
    {
        DOT, // 0
        INT, // 1
        FLOAT, // 2
        CHAR, // 3
        STRING, // 4
        KEYWORD, // 5
        SEMICOLON, // 6
        IDENTIFIER, // 7
        MUL, // 8
        DIV, // 9
        PLUS, // 10
        MINUS, // 12
        LPAREN, // 13
        RPAREN, // 13
        UNKNOWN, // 14
    };
};
