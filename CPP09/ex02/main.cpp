#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    PmergeMe sorter;
    if(sorter.processInput(argc, argv) == 1)
        return 1;
    sorter.sortAndMeasureTime();
    return 0;
}
