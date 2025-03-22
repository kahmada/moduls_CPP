#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    this->data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->data = other.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) {
    struct tm tm;
    return strptime(date.c_str(), "%Y-%m-%d", &tm) != NULL;
}

bool BitcoinExchange::isValidValue(const std::string &value) {
    char *end;
    double val = strtod(value.c_str(), &end);
    return (*end == '\0' && val >= 0 && val <= 1000);
}

double BitcoinExchange::getClosestPrice(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = data.lower_bound(date);
    if (it == data.end() || (it != data.begin() && it->first != date))
        --it;
    return (it != data.end()) ? it->second : 0;
}

void BitcoinExchange::putPrices(const std::string &fileName) {
    BitcoinExchange btc;
    btc.parseDatabase(fileName);
}

void BitcoinExchange::parseDatabase(const std::string &fileName) {
    std::ifstream file(fileName.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line, date;
    double price;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && (iss >> price))
            data[date] = price;
    }
    file.close();
}

void BitcoinExchange::parseInputFile(const std::string &fileName) const {
    std::ifstream file(fileName.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line, date, value;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, date, '|') && std::getline(iss, value)) {
            date.erase(date.find_last_not_of(" ") + 1);
            value.erase(0, value.find_first_not_of(" "));
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!isValidValue(value)) {
                std::cerr << "Error: not a positive number or too large." << std::endl;
                continue;
            }
            double amount = atof(value.c_str());
            double result = amount * getClosestPrice(date);
            std::cout << date << " => " << amount << " = " << result << std::endl;
        }
    }
    file.close();
}


