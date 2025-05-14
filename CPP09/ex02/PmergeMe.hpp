#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <sstream>

class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe &operator=(const PmergeMe &);
        ~PmergeMe();
        
    
        int processInput(int argc, char **argv);
        void sortAndMeasureTime();
        void mergeInsertSortVector(std::vector<int> &arr);
        void mergeInsertSortDeque(std::deque<int> &arr);
        std::vector<int> generateJacobsthalSequence(size_t size);
        void insertIntoSortedVector(std::vector<int>& arr, int value);
        void insertIntoSortedDeque(std::deque<int>& arr, int value);
    };
    


#endif
