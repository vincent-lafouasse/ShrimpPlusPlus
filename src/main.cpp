#include <cassert>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "Lexer.hpp"

namespace Run {
struct Error {};

std::optional<Error> runInterpreter();
std::optional<Error> runFile(const char* path);
}  // namespace Run

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr << "Usage: ./fryer [script.rice]" << std::endl;
        std::exit(1);
    } else if (argc == 2) {
        const char* scriptPath = argv[1];
        Run::runFile(scriptPath);
    } else {
        Run::runInterpreter();
    }
}

namespace Run {
void run(const std::string& line) {
    std::cout << "Running:\t" << line << std::endl;

    Lexer lexer(line);
}

std::optional<std::string> readWholeFile(const char* path);

std::optional<Error> runFile(const char* path) {
    auto maybeText = readWholeFile(path);

    if (maybeText == std::nullopt) {
        std::cerr << "Failed to open script" << path << std::endl;
        std::exit(1);
    }

    run(*maybeText);
    return {};
}

std::optional<Error> runInterpreter() {
    while (true) {
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);
        if (!std::cin.good()) {
            std::exit(1);
        }
        run(line);
    }
    return {};
}

std::optional<std::string> readWholeFile(const char* path) {
    std::ifstream script(path);
    if (!script.good()) {
        return {};
    }

    std::stringstream buffer;
    buffer << script.rdbuf();
    return buffer.str();
}
}  // namespace Run
