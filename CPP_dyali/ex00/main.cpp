#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.parseDatabase("data.csv");
    btc.parseInputFile(argv[1]);

    return 0;
}



