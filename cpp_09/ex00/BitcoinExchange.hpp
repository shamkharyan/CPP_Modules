#ifndef BITCOIN_EXCHANGE_HPP_
#define BITCOIN_EXCHANGE_HPP_

#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
private:
    std::map<std::string, double> mData;
private:
    bool checkDate(const std::string& date);
    bool checkLine(const std::string& line);
public:
    BitcoinExchange();
    BitcoinExchange(const char *dataBase);
};

#endif //BITCOIN_EXCHANGE_HPP_