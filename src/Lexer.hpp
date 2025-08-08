#pragma once

#include <vector>

#include "Token.hpp"

class Lexer {
   public:
    Lexer(const std::string& input) : input(input) {}

    std::vector<std::string> scanTokens() { return {}; }

   private:
    const std::string& input;
    std::size_t head = 0;
};
