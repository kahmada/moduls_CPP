#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if(btc.parse_csv("data.csv") ==1)
    {
        return 1;
    }
    btc.parse_F_inp(argv[1]);

    return 0;
}



