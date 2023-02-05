#include <iostream>

#include "errors.h"
#include "obsidian.h"
#include "collections.h"

using namespace std;
using namespace strings;

int Lexer::line_no;
string Lexer::original_line;

Lexer::Lexer(const string& current_line, int current_line_no)
{
    line_no = current_line_no;
    original_line = trim(current_line);

    cout << line_no << ": ";
    cout << original_line << endl;
}
