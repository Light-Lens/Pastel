#include <iostream>
#include <vector>

#include "errors.h"
#include "obsidian.h"
#include "collections.h"

using namespace std;
using namespace strings;

int lexer::line_no;
string lexer::original_line;

struct lexer::keyword
{
    int id;
    string name;
};

lexer::keyword lexer::Keywords[] = {
    {0, "shout"}
};

lexer::lexer(const string &current_line, int current_line_no)
{
    line_no = current_line_no;
    original_line = trim(current_line);

    Tokenizer();
}

void lexer::Tokenizer()
{
    string tok;
    vector<string> tokens;
    for (int i = 0; i < original_line.size(); i++)
    {
        tok += original_line[i];
        if (isKeyword(tok))
        {
            tokens.push_back(tok);
            tok = "";
        }
    }

    for (int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << endl;
}

bool lexer::isKeyword(const string &str)
{
    for (int i = 0; i < sizeof(Keywords) / sizeof(keyword); i++)
    {
        if (str == Keywords[i].name)
            return true;
    }

    return false;
}
