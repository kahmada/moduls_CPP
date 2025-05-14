#include "RPN.hpp"


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error : must give argument!" << std::endl;
        return 1;
    }

    RPN calculator;
    int result;
    if (calculator.evaluate(argv[1], result)) {
        std::cout << result << std::endl;
    }
    else
        return 1;
    return 0;
}
