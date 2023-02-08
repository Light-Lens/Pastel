#include <iostream>
#include <vector>

#include "errors.h"
#include "obsidian.h"
#include "collections.h"

using namespace std;
using namespace strings;

// ======================= LEXER =======================

int lexer::line_no;
string lexer::original_line;

struct lexer::Token
{
    Tokens::TokenType type;
    string name;
};

string lexer::keywords[] = {
    "shout",
    "input",
    "include",
    "let"
};

lexer::lexer(const string& current_line, int current_line_no)
{
    line_no = current_line_no;
    original_line = trim(current_line);

    vector<lexer::Token> tokens = Tokenizer();
    parser(tokens, original_line, line_no);
}

vector<lexer::Token> lexer::Tokenizer()
{
    string tok;
    vector<Token> tokens;

    for (int i = 0; i < original_line.size(); i++)
    {
        tok += original_line[i];

        if (isEmpty(tok))
            tok = "";

        else if (tok == "#")
            break;

        else if (isKeyword(tok))
        {
            tokens.push_back({Tokens::KEYWORD, tok});
            tok = "";
        }

        else if (isIdentifier(tok))
        {
            i++;
            while (i < original_line.size() && isIdentifier(string(1, original_line[i])))
            {
                tok += original_line[i];
                i++;
            }

            i--;

            tokens.push_back({Tokens::IDENTIFIER, tok});
            tok = "";
        }

        else if (isFloat(tok))
        {
            i++;
            while (i < original_line.size() && isFloat(string(1, original_line[i])))
            {
                tok += original_line[i];
                i++;
            }

            i--;

            tokens.push_back({Tokens::FLOAT, tok});
            tok = "";
        }

        else if (isInt(tok))
        {
            i++;
            while (i < original_line.size() && isdigit(original_line[i]))
            {
                tok += original_line[i];
                i++;
            }

            i--;

            tokens.push_back({Tokens::INT, tok});
            tok = "";
        }

        else if (tok == "'")
        {
            i++;
            while (i < original_line.size() && original_line[i] != '\'')
            {
                if (i > 1) errors::runtime("Multi-character literal at line " + to_string(line_no+1));
                else if (original_line[i] == '\\')
                {
                    i++;
                    switch (original_line[i])
                    {
                        case '\\':
                            tok += "\\";
                            break;

                        case '"':
                            tok += "\"";
                            break;

                        case '\'':
                            tok += "'";
                            break;

                        case 'n':
                            tok += "\n";
                            break;

                        case '0':
                            tok += "\0";
                            break;

                        case 't':
                            tok += "\t";
                            break;

                        case 'r':
                            tok += "\r";
                            break;

                        case 'b':
                            tok += "\b";
                            break;

                        case 'a':
                            tok += "\a";
                            break;

                        case 'f':
                            tok += "\f";
                            break;

                        default:
                            tok += "\\" + string(1, original_line[i]);
                            break;
                    }
                }

                else tok += original_line[i];
                i++;
            }

            tok += original_line[i];
            if (i >= original_line.size())
                errors::runtime("Unterminated string at line " + to_string(line_no+1));

            tokens.push_back({Tokens::CHAR, tok});
            tok = "";
        }

        else if (tok == "\"")
        {
            i++;
            while (i < original_line.size() && original_line[i] != '"')
            {
                if (original_line[i] == '\\')
                {
                    i++;
                    switch (original_line[i])
                    {
                        case '\\':
                            tok += "\\";
                            break;

                        case '"':
                            tok += "\"";
                            break;

                        case '\'':
                            tok += "'";
                            break;

                        case 'n':
                            tok += "\n";
                            break;

                        case '0':
                            tok += "\0";
                            break;

                        case 't':
                            tok += "\t";
                            break;

                        case 'r':
                            tok += "\r";
                            break;

                        case 'b':
                            tok += "\b";
                            break;

                        case 'a':
                            tok += "\a";
                            break;

                        case 'f':
                            tok += "\f";
                            break;

                        default:
                            tok += "\\" + string(1, original_line[i]);
                            break;
                    }
                }

                else tok += original_line[i];
                i++;
            }

            tok += original_line[i];
            if (i >= original_line.size())
                errors::runtime("Unterminated string at line " + to_string(line_no+1));

            tokens.push_back({Tokens::STRING, tok});
            tok = "";
        }

        else if (tok == ";")
        {
            tokens.push_back({Tokens::SEMICOLON, tok});
            tok = "";
        }

        else if (tok == ",")
        {
            tokens.push_back({Tokens::COMMA, tok});
            tok = "";
        }

        else if (tok == ".")
        {
            tokens.push_back({Tokens::DOT, tok});
            tok = "";
        }

        else if (tok == "=")
        {
            tokens.push_back({Tokens::EQUALS, tok});
            tok = "";
        }

        else if (tok == "+")
        {
            tokens.push_back({Tokens::PLUS, tok});
            tok = "";
        }

        else if (tok == "-")
        {
            tokens.push_back({Tokens::MINUS, tok});
            tok = "";
        }

        else if (tok == "*")
        {
            tokens.push_back({Tokens::MUL, tok});
            tok = "";
        }

        else if (tok == "/")
        {
            tokens.push_back({Tokens::DIV, tok});
            tok = "";
        }

        else if (tok == "(")
        {
            tokens.push_back({Tokens::LPAREN, tok});
            tok = "";
        }

        else if (tok == ")")
        {
            tokens.push_back({Tokens::RPAREN, tok});
            tok = "";
        }

        else
        {
            tokens.push_back({Tokens::UNKNOWN, tok});
            tok = "";
        }
    }

    return tokens;
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

bool lexer::isFloat(const string& str)
{
    if (str.empty())
        return false;

    int dot_count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            continue;

        else if (str[i] == '.' && dot_count < 2)
        {
            dot_count++;
            continue;
        }

        return false;
    }

    return true;
}

bool lexer::isIdentifier(const string& str)
{
    if (str.empty())
        return false;

    for (int i = 0; i < str.size(); i++)
    {
        if (!isalpha(str[i]))
            return false;
    }

    return true;
}

// ======================= PARSER =======================

parser::parser(vector<lexer::Token> tokens, string original_line, int line_no)
{
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].type == Tokens::STRING) cout << tokens[i].name << endl;
    }
}
