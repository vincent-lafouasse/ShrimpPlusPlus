#pragma once

#include <optional>

#include "Literal.hpp"

class Token {
   public:
    enum class Kind {
      // keywords
        Function,
        Let,
      // operators
        LeftParen,
        RightParen,
        LeftBrace,
        RightBrace,
        SemiColon,
        Plus,
        Minus,
        Times,
        Divides,
      // misc
        Identifier,
        Eof,
    };

    Kind kind;
    std::optional<Literal> literal;
};
