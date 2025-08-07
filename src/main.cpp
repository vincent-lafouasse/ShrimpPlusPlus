#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./fryer script.rice" << std::endl;
        std::exit(1);
    }

    const char* scriptPath = argv[1];
    std::cout << "input is " << scriptPath << std::endl;

    std::ifstream script(scriptPath);
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
