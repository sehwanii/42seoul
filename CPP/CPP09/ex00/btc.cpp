#include "btc.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits.h>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rateMap(other._rateMap) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _rateMap = other._rateMap;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool isValidDateFormat(const std::string& date) {
    return date.size() == 10 && date[4] == '-' && date[7] == '-';
}

float parseValue(const std::string& valueStr, bool& valid, bool& tooLarge) {
    std::istringstream iss(valueStr);
    float value;
    iss >> value;
    valid = !iss.fail() && iss.eof();
    tooLarge = (value > 1000);
    return value;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open DB file." << std::endl;
        std::exit(1);
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr)) {
            std::istringstream vs(valueStr);
            float value;
            vs >> value;
            _rateMap[date] = value;
        }
    }
}

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);

        if (!isValidDateFormat(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        bool valid, tooLarge;
        float value = parseValue(valueStr, valid, tooLarge);
        if (!valid) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (tooLarge) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        std::map<std::string, float>::const_iterator it = _rateMap.lower_bound(date);
        if (it == _rateMap.end() || it->first != date) {
            if (it == _rateMap.begin()) {
                std::cerr << "Error: no earlier date found." << std::endl;
                continue;
            }
            --it; // use the closest previous date
        }
        float result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}
