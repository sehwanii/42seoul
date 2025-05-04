#include <iostream>
#include <string>
#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    if (input.find('(') != std::string::npos || input.find(')') != std::string::npos) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        int result = evaluateRPN(input);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
