#pragma once
#include <optional>
#include <vector>
#include <iostream>
#include <cctype> //24-10-2024 : uday :  For isalpha, isalnum, isdigit

//24-10-2024 : uday :  Enum to represent the types of tokens
enum class TokenType {
    _Ret,         //24-10-2024 : uday :  Return statement token (e.g., "ret")
    _Intliteral,  //24-10-2024 : uday :  Integer literal token (e.g., 123)
    _SemiColon    //24-10-2024 : uday :  Semicolon token (e.g., ";")
};

//24-10-2024 : uday :  Token structure to store the type and optionally a value
struct Token {
    TokenType type;                  //24-10-2024 : uday :  The type of the token
    std::optional<std::string> value{}; //24-10-2024 : uday :  Optional value (used for literals)
};

class Tokenizer
{
private:
    const std::string fg_src; //24-10-2024 : uday :  The source code string to tokenize
    size_t fg_index = 0;         //24-10-2024 : uday :  The current position in the source code

    //24-10-2024 : uday :  Function to peek at the character 'count' positions ahead
    [[nodiscard]] inline std::optional<char> peek(int count = 1) const {
        if (fg_index + count - 1 >= fg_src.length()) {
            return {}; //24-10-2024 : uday :  If out of bounds, return empty optional
        }
        else {
            return fg_src.at(fg_index + count - 1); //24-10-2024 : uday :  Return character at the offset
        }
    }

    //24-10-2024 : uday :  Function to consume the current character and move to the next one
    inline char consume() {
        return fg_src.at(fg_index++); //24-10-2024 : uday :  Returns the current char and then increments index
    }

public:
    //24-10-2024 : uday :  Constructor to initialize the Tokenizer with the source string
    explicit Tokenizer(const std::string& src)
        : fg_src(std::move(src))
    {
    }

    //24-10-2024 : uday :  Function to tokenize the source code and return a vector of tokens
    std::vector<Token> Tokenize() {
        std::vector<Token> Tokens{};  //24-10-2024 : uday :  Vector to store the recognized tokens
        std::string buf;              //24-10-2024 : uday :  Buffer to store characters as we form tokens
        
        //24-10-2024 : uday :  Tokenization loop - runs while there are characters left to process
        while (peek().has_value()) {
            //24-10-2024 : uday :  Check for alphabetic characters (for keywords like "ret")
            if (std::isalpha(peek().value())) {
                buf.push_back(consume()); //24-10-2024 : uday :  Consume the first letter
                //24-10-2024 : uday :  Continue consuming alphanumeric characters (for complete words)
                while (peek().has_value() && std::isalnum(peek().value())) {
                    buf.push_back(consume());
                }

                //24-10-2024 : uday :  Check if the word is "ret"
                if (buf == "ret") {
                    Tokens.push_back({.type = TokenType::_Ret}); //24-10-2024 : uday :  Push "ret" token
                    buf.clear(); //24-10-2024 : uday :  Clear buffer for next token
                    continue;
                }
                else {
                    //24-10-2024 : uday :  If unrecognized keyword, show error
                    std::cerr << "Error: Unrecognized keyword '" << buf << "'" << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            //24-10-2024 : uday :  Check for numeric literals (integers)
            else if (std::isdigit(peek().value())) {
                buf.push_back(consume()); //24-10-2024 : uday :  Consume first digit
                //24-10-2024 : uday :  Continue consuming digits
                while (peek().has_value() && std::isdigit(peek().value())) {
                    buf.push_back(consume());
                }
                //24-10-2024 : uday :  Push integer literal token
                Tokens.push_back({.type = TokenType::_Intliteral, .value = buf});
                buf.clear(); //24-10-2024 : uday :  Clear buffer for next token
                continue;
            }
            //24-10-2024 : uday :  Check for semicolon
            else if (peek().value() == ';') {
                Tokens.push_back({.type = TokenType::_SemiColon}); //24-10-2024 : uday :  Push semicolon token
                consume(); //24-10-2024 : uday :  Consume the semicolon
                continue;
            }
            //24-10-2024 : uday :  Skip over whitespace characters
            else if (std::isspace(peek().value())) {
                consume(); //24-10-2024 : uday :  Consume the space and move on
                continue;
            }
            //24-10-2024 : uday :  Handle any unrecognized characters
            else {
                std::cerr << "Error: Unrecognized character '" << peek().value() << "'" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        fg_index = 0; //24-10-2024 : uday :  Reset the index after tokenization
        return Tokens; //24-10-2024 : uday :  Return the vector of tokens
    }
};
