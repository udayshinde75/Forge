#pragma once
#include "./Parser.hpp"
#include <sstream>

class Generator
{
private:
    const NodeRet fg_root;
public:
    inline Generator(NodeRet root)
        :fg_root(std::move(root))
        {

        }

    [[nodiscard]]std::string generate() const
    {
        std :: stringstream output;
        output << ".global _start\n_start:\n";
        output << "    mov x0, " << fg_root.expr._Intliteral.value.value() << "\n";
        output << "    mov x8, 93\n";
        output << "    svc 0\n";
        return output.str();
    }
};

