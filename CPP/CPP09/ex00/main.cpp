#include "btc.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.loadDatabase("data.csv"); // 내부 DB는 항상 "data.csv"로 가정
    btc.processInput(argv[1]);

    return 0;
}
