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
    
        void mergeInsertSortVector(std::vector<int> &arr); // Implémentation du tri par insertion fusion
        void mergeInsertSortDeque(std::deque<int> &arr); // Implémentation du tri par insertion fusion
        void mergeVector(std::vector<int> &arr, std::vector<int> &left, std::vector<int> &right);
        void mergeDeque(std::deque<int> &arr, std::deque<int> &left, std::deque<int> &right);
        
        // Fonction qui génère la séquence de Jacobsthal, utilisée pour améliorer l'ordre d'insertion lors de la fusion
        std::vector<int> generateJacobsthalSequence(size_t size);
    
        // Helper functions for insertion during merge
        void insertIntoSortedVector(std::vector<int>& arr, int value);  // Déclaration pour tri avec std::vector
        void insertIntoSortedDeque(std::deque<int>& arr, int value);    // Déclaration pour tri avec std::deque
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe &operator=(const PmergeMe &);
        ~PmergeMe();
    
        void processInput(int argc, char **argv);
        void sortAndMeasureTime();
    };
    


#endif
