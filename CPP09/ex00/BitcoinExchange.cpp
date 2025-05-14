#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc) {
    this->data = btc.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc) {
    if (this != &btc)
        this->data = btc.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


float BitcoinExchange::get_price(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = data.lower_bound(date);//retourne un itérateur vers : le premier élément dont la clé est ≥ à date.
    // ila malgach date kimchi li kbr mnha  7na bghina li sghr mnha ya3ni it --;
    if (it == data.end() || (it != data.begin() && it->first != date))
        --it;

    if (it != data.end())
        return it->second;
    else
        return 0;
}

int  BitcoinExchange::parse_csv(const std::string &fileName) {
    std::ifstream file(fileName.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    std::string date;
    float price;
    bool hasData = false;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty database file." << std::endl;
        return 1;
    }

    if (line != "date,exchange_rate")
    {
        std::cerr << "Error: database header must be 'date,exchange_rate'" << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && (iss >> price)) {

            data[date] = price;
            hasData = true;
        }
    }

    if (!hasData) {
        std::cerr << "Error: database contains no valid data." << std::endl;
        return 1;
    }

    file.close();
    return 0;
}

int is_not_positiv(const std::string& str)
{
    if (str.empty() || str[0] == '-')
        return 1;

    int dotCount = 0;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return 1;
        }
        else if (!isdigit(str[i]))
        {
            return 1;
        }
    }
    if (str == ".")
        return 1;

    return 0;
}

int is_large(std::string str)
{
    if (str.length() > 10)
        return 1;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return 1;
    }
    float value = atof(str.c_str());
    if (value > 1000)
        return 1;
    return 0;
}
bool BitcoinExchange::is_valid_date(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); ++i)
    {
        if (!isdigit(yearStr[i])) 
            return false;
    }
    for (size_t i = 0; i < monthStr.length(); ++i)
    {
        if (!isdigit(monthStr[i])) 
            return false;
    }
    for (size_t i = 0; i < dayStr.length(); ++i)
    {
        if (!isdigit(dayStr[i])) 
            return false;
    }
    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::parse_F_inp(const std::string &fileName) const 
{
    std::ifstream file(fileName.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line, date, value;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty file." << std::endl;
        return;
    }
    if (line != "date | value")
    {
        std::cerr << "Error: first line must be 'date | value'" << std::endl;
        return;
    }

    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        if (!(std::getline(iss, date, '|') && std::getline(iss, value))) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = trim(date);
        value = trim(value);


        if (date.empty() || value.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!is_valid_date(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (is_not_positiv(value)) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (is_large(value)) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float amount = atof(value.c_str());
        float result = amount * get_price(date);
        std::cout << date << " => " << amount << " = " << result << std::endl;
    }

    file.close();
}




