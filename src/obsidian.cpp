#include <iostream>
#include <vector>

#include "errors.h"
#include "obsidian.h"
#include "collections.h"

using namespace std;
using namespace strings;

int lexer::line_no;
string lexer::original_line;

struct lexer::Token
{
    TokenType type;
    string name;
};

string lexer::keywords[] = {
    "shout"
};

lexer::lexer(const string& current_line, int current_line_no)
{
    line_no = current_line_no;
    original_line = trim(current_line);

    Tokenizer();
}

void lexer::Tokenizer()
{
    string tok;
    vector<Token> tokens;

    for (int i = 0; i < original_line.size(); i++)
    {
        tok += original_line[i];
        if (isEmpty(tok))
            tok = "";

        else if (isKeyword(tok))
        {
            tokens.push_back({KEYWORD, tok});
            tok = "";
        }

        else if (isInt(tok))
        {
            tokens.push_back({INT, tok});
            tok = "";
        }

        else if (tok == ".")
        {
            tokens.push_back({DOT, tok});
            tok = "";
        }

        else if (tok == "+")
        {
            tokens.push_back({PLUS, tok});
            tok = "";
        }

        else if (tok == "-")
        {
            tokens.push_back({MINUS, tok});
            tok = "";
        }

        else if (tok == "*")
        {
            tokens.push_back({MUL, tok});
            tok = "";
        }

        else if (tok == "/")
        {
            tokens.push_back({DIV, tok});
            tok = "";
        }

        else if (tok == "(")
        {
            tokens.push_back({LPAREN, tok});
            tok = "";
        }

        else if (tok == ")")
        {
            tokens.push_back({RPAREN, tok});
            tok = "";
        }
    }

    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i].name << endl;
        cout << endl;
    }
}

bool lexer::isKeyword(const string &str)
{
    for (int i = 0; i < (sizeof(keywords) / sizeof(keywords[0])); i++)
    {
        if (str == keywords[i])
            return true;
    }

    return false;
}

bool lexer::isInt(const string& str)
{
    if (str.empty())
        return false;

    for (int i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}
