#pragma once
#include <iostream>

namespace Tokens
{
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
        COMMA, // 15
        EQUALS // 16
    };
};

class lexer
{
public:
    struct Token;

private:
    static int line_no;
    static std::string original_line;
    static std::string keywords[];

public:
    lexer(const std::string& current_line, int current_line_no);

private:
    std::vector<lexer::Token> Tokenizer();
    bool isKeyword(const std::string &str);
    bool isInt(const std::string& str);
    bool isFloat(const std::string& str);
    bool isIdentifier(const std::string& str);
};

class parser
{
public:
    parser(std::vector<lexer::Token> tokens, std::string original_line, int line_no);
};
