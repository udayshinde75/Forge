#pragma once
#include <optional>
#include <vector>
#include <iostream>
#include <cctype> 
#include "./Tokenizer.hpp"

//24-10-2024 : uday : NodeExpr represents an expression node in the AST, here handling integer literals.
struct NodeExpr {
    Token _Intliteral; //24-10-2024 The integer literal token stored in the expression node
};

//24-10-2024 : uday : NodeRet represents a return statement node in the AST.
struct NodeRet {
    NodeExpr expr; //24-10-2024 : uday : The return statement contains an expression node
};

class Parser
{
private:
    const std::vector<Token> fg_tokens; //24-10-2024 : uday : Vector of tokens to be parsed
    size_t fg_index = 0;                //24-10-2024 : uday :  Index to track the current position in the token stream

    //24-10-2024 : uday :  Peek at the next token in the stream without consuming it.
    [[nodiscard]] inline std::optional<Token> peek(int count = 1) const {
        if (fg_index + count - 1 >= fg_tokens.size()) {
            return {}; //24-10-2024 : uday :  Return empty optional if we're out of bounds
        } else {
            return fg_tokens.at(fg_index + count - 1); //24-10-2024 : uday :  Return the token at the offset
        }
    }

    //24-10-2024 : uday :  Consume the current token and move to the next one.
    inline Token consume() {
        return fg_tokens.at(fg_index++); //24-10-2024 : uday :  Return current token and increment the index
    }

public:
    //24-10-2024 : uday :  Constructor to initialize the parser with a vector of tokens
    inline explicit Parser(std::vector<Token> tokens)
        : fg_tokens(std::move(tokens))
    {
    }

    //24-10-2024 : uday :  Parse an expression (currently only handling integer literals)
    std::optional<NodeExpr> parse_expr() {
        if (peek().has_value() && peek().value().type == TokenType::_Intliteral) {
            //24-10-2024 : uday :  Consume the integer literal and return an expression node
            return NodeExpr{._Intliteral = consume()};
        } else {
            return {}; //24-10-2024 : uday :  If it's not an integer literal, return an empty optional
        }
    }

    //24-10-2024 : uday :  Main parse function to handle return statements and semicolons
    std::optional<NodeRet> parse() {
        std::optional<NodeRet> ret_node; //24-10-2024 : uday :  Node to hold the return statement

        while (peek().has_value()) { // Loop while there are tokens to parse
            //24-10-2024 : uday :  Check if the current token is a return statement ("ret")
            if (peek().value().type == TokenType::_Ret) {
                consume(); //24-10-2024 : uday :  Consume the "ret" token

                //24-10-2024 : uday :  Parse the expression following "ret"
                if (auto node_expr = parse_expr()) {
                    ret_node = NodeRet{.expr = node_expr.value()}; //24-10-2024 : uday :  Store the expression
                } else {
                    std::cerr << "Error: Invalid expression after 'ret'" << std::endl;
                    exit(EXIT_FAILURE); //24-10-2024 : uday :  Exit on error
                }

                //24-10-2024 : uday :  After the expression, check for the semicolon
                if (peek().has_value() && peek().value().type == TokenType::_SemiColon) {
                    consume(); //24-10-2024 : uday :  Consume the semicolon
                } else {
                    std::cerr << "Error: Missing semicolon after return statement" << std::endl;
                    exit(EXIT_FAILURE); //24-10-2024 : uday :  Exit on error
                }

                //24-10-2024 : uday :  Return the parsed return node after successful parsing
                return ret_node;
            } else {
                //24-10-2024 : uday :  Handle any unexpected tokens
                std::cerr << "Error: Expected 'ret' statement" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        fg_index = 0; //24-10-2024 : uday :  Optionally reset the index (can be removed if not needed)
        return ret_node; //24-10-2024 : uday :  Return the parsed return node
    }
};
