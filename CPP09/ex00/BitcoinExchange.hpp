#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>



class BitcoinExchange {
private:
    std::map<std::string, float> data;
public:
    bool is_valid_date(const std::string &date) const;
    float get_price(const std::string &date) const;
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &btc);
    BitcoinExchange &operator=(const BitcoinExchange &btc);
    ~BitcoinExchange();

    int  parse_csv(const std::string &fileName);
    void parse_F_inp(const std::string &fileName) const;
};  

#endif