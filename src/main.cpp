#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>
#include "./Tokenizer.hpp"
#include "./Parser.hpp"
#include "./Generation.hpp"
/*****************************************Basic Program to convert .Fg file to Assembly Language****************************************************/
//21-10-2024 : Uday : created class for token
/*
enum class TokenType {
    _Ret,
    _Intliteral,
    _SemiColon
};

struct Token {
    TokenType type;
    std::optional<std::string> value{};
};

//21-10-2024 : Uday : Function to tokenize the string into tokens (return, integer literals, and semicolons)
std::vector<Token> Tokenize(const std::string& str) {
    std::vector<Token> Tokens{};
    std::string buf;
    
    for (size_t i = 0; i < str.length(); i++) {
        char c = str.at(i);

        //21-10-2024 : Uday : Check for alphabetic characters (for "ret")
        if (std::isalpha(c)) {
            buf.push_back(c);
            i++;
            while (i < str.length() && std::isalnum(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;

            if (buf == "ret") {
                Tokens.push_back({.type = TokenType::_Ret});
                buf.clear();
                continue;
            } else {
                std::cerr << "Error: Unrecognized keyword '" << buf << "'" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        //21-10-2024 : uday : Check for digit characters (for integers)
        else if (std::isdigit(c)) {
            buf.push_back(c);
            i++;
            while (i < str.length() && std::isdigit(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            Tokens.push_back({.type = TokenType::_Intliteral, .value = buf});
            buf.clear();
        }
        //21-10-2024 : uday : Check for semicolon
        else if (c == ';') {
            Tokens.push_back({.type = TokenType::_SemiColon});
        }
        //21-10-2024 : uday : Skip spaces
        else if (std::isspace(c)) {
            continue;
        }
        //21-10-2024 : uday : Handle invalid characters
        else {
            std::cerr << "Error: Unrecognized character '" << c << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return Tokens;
}
*/
//21-10-2024 : uday : Function to convert array of tokens into assembly code
/*
std::string TokensToAsm(const std::vector<Token>& Tokens){
    std :: stringstream output;
    output << ".global _start\n_start:\n";
    for (int i = 0 ; i < Tokens.size() ; i++)
    {
        const Token& token = Tokens.at(i);
        if (token.type == TokenType::_Ret)
        {
            if (i + 1 < Tokens.size() && Tokens.at(i + 1).type == TokenType::_Intliteral)
            {
                if (i + 2 < Tokens.size() && Tokens.at(i + 2).type == TokenType::_SemiColon)
                {
                    output << "    mov x0, " <<Tokens.at(i + 1).value.value() << "\n";
                    output << "    mov x8, 93\n";
                    output << "    svc 0\n";
                }
                
            }
                
        }
        
    }
    return output.str();
    
}
*/

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect usage. Correct Usage is: ./program <input.Fg>" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::fstream input(argv[1], std::ios::in);
    
    //21-10-2024 : uday : Check if the file opened successfully
    if (!input.is_open()) {
        std::cerr << "Failed to open the file: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }
    
    std::stringstream contents_stream;
    contents_stream << input.rdbuf(); // Read the entire file into the stream
    input.close();
    std::string Content = contents_stream.str(); // Convert stream to string

    Tokenizer tokenizer(std :: move(Content));


    //21-10-2024 : uday : Tokenize the content
    std::vector<Token> tokens = tokenizer.Tokenize();
    Parser parser(std::move(tokens));
    std::optional <NodeRet> tree = parser.parse();
    if (!tree.has_value())
    {
        std :: cerr << "No exit statement found." << std :: endl;
        exit(EXIT_FAILURE);
    }
    
    Generator generator(tree.value());

    //21-10-2024 : uday : Output the tokens for debugging
    for (const auto& token : tokens) {
        switch (token.type) {
            case TokenType::_Ret:
                std::cout << "Token: return" << std::endl;
                break;
            case TokenType::_Intliteral:
                std::cout << "Token: Intliteral, Value: " << (token.value ? *token.value : "") << std::endl;
                break;
            case TokenType::_SemiColon:
                std::cout << "Token: Semicolon" << std::endl;
                break;
        }
    }
    std :: fstream file("../out.s", std :: ios :: out);
    file << generator.generate();
    file.close();
    //std :: cout << TokensToAsm(tokens);

    //21-10-2024 : uday : commands to create an executable code.
    system("as -o ../out.o ../out.s");
    system("ld -o ../out ../out.o");

    return EXIT_SUCCESS;
}
