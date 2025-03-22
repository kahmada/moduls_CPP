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

    void mergeInsertSortVector(std::vector<int> &arr);// implémentent le tri par insertion fusion
    void mergeInsertSortDeque(std::deque<int> &arr);// implémentent le tri par insertion fusion
    void mergeVector(std::vector<int> &arr, std::vector<int> &left, std::vector<int> &right);
    void mergeDeque(std::deque<int> &arr, std::deque<int> &left, std::deque<int> &right);
    //mergeVector() et mergeDeque() fusionnent les sous-listes triées en utilisant la séquence de Jacobsthal.
    std::vector<int> generateJacobsthalSequence(size_t size);//génère la séquence de Jacobsthal, utilisée pour améliorer l'ordre d'insertion lors de la fusion.

public:
    PmergeMe();
    PmergeMe(const PmergeMe &);
    PmergeMe &operator=(const PmergeMe &);
    ~PmergeMe();

    void processInput(int argc, char **argv);
    void sortAndMeasureTime();
};


#endif
