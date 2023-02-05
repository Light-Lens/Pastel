#pragma once
#include <iostream>

class lexer
{
public:
    lexer(const std::string& current_line, int current_line_no);

private:
    void Tokenizer();
    bool isKeyword(const std::string &str);

private:
    struct keyword;

    static int line_no;
    static std::string original_line;
    static keyword Keywords[];
};
