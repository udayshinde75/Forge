Forge Compiler Project
/*****************************Date:21 Oct 2024***********************************/
The Forge project is an ongoing development of a custom compiler for a new programming language called Forge, with a special focus on targeting the Linux ARM64 architecture. This compiler is designed to process code written in the Forge language, translating it into machine code optimized for ARM64 systems. The project is in its early stages, concentrating on core functionalities such as parsing input files, managing tokens, and setting up essential file-handling mechanisms. Future developments will include expanding the language's syntax and semantics, creating an efficient code generation pipeline, and optimizing the compiled output for performance across ARM64-based Linux platforms.

/***********Start-21/10/2024(Overview)***********/

CMakeLists.txt:

    This file is used to set up the CMake project for the Forge compiler. It specifies that the project will use C++ standard 23 and includes src/main.cpp as the source file for the executable named "Forge."

main.cpp:

    Tokenization:
        The code reads an input .Fg file, which contains a simple syntax for returning integer literals (e.g., ret 0;).
        The function Tokenize() breaks down the input string into tokens based on recognized patterns:
            ret keyword (return statement)
            Integer literals (numbers)
            Semicolons (;)
        It returns a list of tokens where each token is of type _Ret, _Intliteral, or _SemiColon.

    Converting Tokens to Assembly:
        The function TokensToAsm() takes the list of tokens and generates corresponding ARM64 assembly instructions.
        Specifically, it looks for a sequence of tokens representing ret <int>; and converts them into assembly:
            Moves the integer literal to register x0.
            Executes a system call (svc 0) to exit with the return code.

    Main Execution:
        The main() function reads a .Fg input file, tokenizes its contents, and converts the tokens into assembly.
        The generated assembly code is written to out.s.
        The program then assembles (as -o out.o out.s) and links (ld -o out out.o) the code to produce an executable named out.

main.Fg:

    This is a simple .Fg file that contains a single statement:

        ret 0;

    This tells the program to return 0 as the exit code, which will be translated into assembly and then compiled into an executable.

/***********End-21/10/2024(Overview)***********/