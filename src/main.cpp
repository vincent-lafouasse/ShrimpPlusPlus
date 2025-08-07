#include <cassert>
#include <fstream>
#include <iostream>

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
}
