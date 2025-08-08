#include <cassert>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "Lexer.hpp"

// ErrorKind should implement ErrorKind::format()
template <typename ErrorKind>
struct Error {
    ErrorKind kind;
    std::string message;
    std::size_t lineNumber;

    std::string format() const {
        return "";
    }
};

namespace Run {
void runInterpreter();
void runFile(const char* path);
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
struct Error {};

std::optional<Error> run(const std::string& line) {
    std::cout << "Running:\t" << line << std::endl;

    Lexer lexer(line);

    return {};
}

std::optional<std::string> readWholeFile(const char* path);

void runFile(const char* path) {
    auto maybeText = readWholeFile(path);

    if (maybeText == std::nullopt) {
        std::cerr << "Failed to open script" << path << std::endl;
        std::exit(1);
    }

    run(*maybeText);
}

void runInterpreter() {
    while (true) {
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);
        if (!std::cin.good()) {
            std::exit(1);
        }
        run(line);
    }
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
