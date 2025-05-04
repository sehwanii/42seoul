#ifndef BTC_HPP
#define BTC_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _rateMap;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename) const;
};

#endif