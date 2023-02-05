#pragma once
#include <iostream>

class Lexer
{
private:
    static int line_no;
    static std::string original_line;

public:
    Lexer(const std::string& current_line, int current_line_no);
};
