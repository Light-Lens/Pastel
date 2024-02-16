#include <iostream>
#include <vector>
#include <cctype>

enum TokenType {
    IDENTIFIER,
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    EQUALS,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
};

class Tokenizer {
public:
    Tokenizer(const std::string& input) : input(input), position(0) {}

    Token getNextToken() {
        skipWhitespace();

        if (position >= input.length()) {
            return {END_OF_FILE, ""};
        }

        char currentChar = input[position];

        if (isalpha(currentChar)) {
            return parseIdentifier();
        } else if (isdigit(currentChar)) {
            return parseNumber();
        } else {
            position++;
            switch (currentChar) {
                case '+':
                    return {PLUS, "+"};
                case '-':
                    return {MINUS, "-"};
                case '*':
                    return {MULTIPLY, "*"};
                case '/':
                    return {DIVIDE, "/"};
                case '=':
                    return {EQUALS, "="};
                case ';':
                    return {END_OF_FILE, ";"};
                default:
                    // Handle unknown characters or syntax errors
                    std::cerr << "Error: Unknown character '" << currentChar << "'\n";
                    return {END_OF_FILE, ""};
            }
        }
    }

private:
    void skipWhitespace() {
        while (position < input.length() && isspace(input[position])) {
            position++;
        }
    }

    Token parseIdentifier() {
        std::string identifier;
        while (position < input.length() && (isalnum(input[position]) || input[position] == '_')) {
            identifier += input[position];
            position++;
        }
        return {IDENTIFIER, identifier};
    }

    Token parseNumber() {
        std::string number;
        while (position < input.length() && isdigit(input[position])) {
            number += input[position];
            position++;
        }
        return {NUMBER, number};
    }

private:
    const std::string& input;
    std::size_t position;
};

int main() {
    std::string input = "x = 10 + y * 5;";

    Tokenizer tokenizer(input);

    Token token;
    do {
        token = tokenizer.getNextToken();
        std::cout << "Token: Type = " << token.type << ", Value = '" << token.value << "'\n";
    } while (token.type != END_OF_FILE);

    return 0;
}
