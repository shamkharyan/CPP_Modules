#include "BitcoinExchange.hpp"
#include <sstream>

BitcoinExchange::BitcoinExchange(const char* dataBase)
{

}

bool BitcoinExchange::checkDate(const std::string& date)
{
    if (date.size() != 10)
        return false;

    std::stringstream ss(date);
    std::string token;

    std::getline(ss, token, '-');
    if (token.size() != 4)
        return false;
    if (token.find_first_not_of("0123456789") != std::string::npos)
        return false;
    int year = std::stoi(token);

    std::getline(ss, token, '-');
    if (token.size() != 2)
        return false;
    if (!std::isdigit(token[0]) || !std::isdigit(token[1]))
        return false;
    int month = std::stoi(token);
    if (month < 0 || month > 12)
        return false;

    std::getline(ss, token, '-');
    if (token.size() != 2)
        return false;
    if (!std::isdigit(token[0]) || !std::isdigit(token[1]))
        return false;
    int day = std::stoi(token);
    if (day < 0 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day >= 31)
        return false;
    if (month == 2)
    {
        if (year % 400 == 0 && day > 29)
            return false;
        if (year % 100 == 0 && day >= 29)
            return false;
        if (year % 4 == 0 && day > 29)
            return false;
        if (day >= 29)
            return false;
    }
    return true;
}