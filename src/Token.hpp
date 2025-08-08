#pragma once

#include <optional>

#include "Literal.hpp"

class Token {
   public:
    enum class Kind {
        LeftParen,
        RightParen,
        Eof,
    };

    Kind kind;
    std::optional<Literal> literal;
};
