#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

class BitcoinExchange {
private:
    std::map<std::string, double> data;//Stocke la date comme clé et le prix comme valeur dans la structure data.
    
    static bool isValidDate(const std::string &date);
    static bool isValidValue(const std::string &value);
    double getClosestPrice(const std::string &date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &btc);
    BitcoinExchange &operator=(const BitcoinExchange &btc);
    ~BitcoinExchange();

    static void putPrices(const std::string &fileName);
    void parseDatabase(const std::string &fileName);
    void parseInputFile(const std::string &fileName) const;
};

#endif