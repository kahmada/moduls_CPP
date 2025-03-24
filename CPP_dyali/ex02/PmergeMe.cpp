#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        int num;
        char extra;

        if (!(ss >> num) || ss >> extra) { // Vérifie si un caractère reste après l'entier
            std::cerr << "Error: Invalid input." << std::endl;
            exit(1);
        }

        if (num < 0) { // Vérification des nombres négatifs
            std::cerr << "Error: Negative numbers are not allowed." << std::endl;
            exit(1);
        }

        _vector.push_back(num);
        _deque.push_back(num);
    }
}


// std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size) {
//     std::vector<int> seq;
//     seq.push_back(0);
//     seq.push_back(1);

//     while (seq.back() < static_cast<int>(size)) {
//         seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);//J(n)=J(n−1)+2×J(n−2)
//     }
//     return seq;
// }

std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<int> seq = {0, 1}; 

    while (true) {
        int nextValue = seq.back() + 2 * seq[seq.size() - 2];  // J(n) = J(n-1) + 2*J(n-2)
        if (nextValue >= static_cast<int>(size)) break;  // Stoppe, wenn größer als 'size'
        seq.push_back(nextValue);
    }

    return seq;
}


void PmergeMe::mergeInsertSortVector(std::vector<int> &arr) {
    if (arr.size() < 2) return;
    size_t mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    mergeInsertSortVector(left);
    mergeInsertSortVector(right);
    mergeVector(arr, left, right);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &arr) {
    if (arr.size() < 2) return;
    size_t mid = arr.size() / 2;
    std::deque<int> left(arr.begin(), arr.begin() + mid);
    std::deque<int> right(arr.begin() + mid, arr.end());
    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);
    mergeDeque(arr, left, right);
}

void PmergeMe::mergeVector(std::vector<int> &arr, std::vector<int> &left, std::vector<int> &right) {
    arr.clear();

    std::vector<int> jacobsthal = generateJacobsthalSequence(left.size() + right.size()); // Assure-toi que cette fonction est bien compatible avec C++98

    size_t i = 0, j = 0;

    for (size_t index = 0; index < jacobsthal.size(); ++index) { // Remplacement de la boucle range-based
        size_t k = jacobsthal[index]; // Récupération de la valeur

        while (k-- && i < left.size() && j < right.size())
            arr.push_back((left[i] < right[j]) ? left[i++] : right[j++]);
    }

    while (i < left.size()) arr.push_back(left[i++]);
    while (j < right.size()) arr.push_back(right[j++]);
}

void PmergeMe::mergeDeque(std::deque<int> &arr, std::deque<int> &left, std::deque<int> &right) {
    arr.clear();

    std::vector<int> jacobsthal = generateJacobsthalSequence(left.size() + right.size());

    size_t i = 0, j = 0;

    for (size_t index = 0; index < jacobsthal.size(); ++index) { // Remplacement de la boucle range-based
        size_t k = jacobsthal[index]; // Récupération de la valeur

        while (k-- && i < left.size() && j < right.size())
            arr.push_back((left[i] < right[j]) ? left[i++] : right[j++]);
    }

    while (i < left.size()) arr.push_back(left[i++]);
    while (j < right.size()) arr.push_back(right[j++]);
}


void PmergeMe::sortAndMeasureTime() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    clock_t startVector = clock();
    mergeInsertSortVector(_vector);
    clock_t endVector = clock();
    double timeVector = (double)(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeque = clock();
    mergeInsertSortDeque(_deque);
    clock_t endDeque = clock();
    double timeDeque = (double)(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << timeDeque << " us" << std::endl;
}
