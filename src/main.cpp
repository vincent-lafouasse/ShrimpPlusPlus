#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Token.hpp"

// driver
void runInterpreter();
void runFile(const char* path);

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr << "Usage: ./fryer [script.rice]" << std::endl;
        std::exit(1);
    } else if (argc == 2) {
        const char* scriptPath = argv[1];
        runFile(scriptPath);
    } else {
        runInterpreter();
    }
}


void runInterpreter() {}

void runFile(const char* path) {
    std::cout << "input is " << path << std::endl;

    std::ifstream script(path);
    if (!script.good()) {
        std::cerr << "Failed to open script" << std::endl;
        std::exit(1);
    }

    std::vector<std::string> statements;
    while (script.good()) {
        std::string current;
        std::getline(script, current, ';');
        statements.push_back(current);
    }

    for (std::size_t i = 0; i < statements.size(); ++i) {
        std::cout << "Statement " << i << ":\t";
        std::cout << statements[i] << '\n';
    }
}
