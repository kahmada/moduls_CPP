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

int PmergeMe::processInput(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        int num;
        char extra;

        if (!(ss >> num) || ss >> extra) {
            std::cerr << "Error: Invalid input." << std::endl;
            return 1;
        }

        if (num < 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        _vector.push_back(num);
        _deque.push_back(num);
    }
    return 0;
}


std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<int> seq; 
    seq.push_back(0);
    seq.push_back(1);
    while (true) {
        int nextValue = seq.back() + 2 * seq[seq.size() - 2];  // J(n) = J(n-1) + 2*J(n-2)
        if (nextValue >= static_cast<int>(size))
            break;
        seq.push_back(nextValue);
    }
    return seq;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    if (arr.size() < 2)
        return;
    std::vector<int> larger;
    std::vector<int> smaller;
    size_t i = 0;
    for (; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1]) {
            smaller.push_back(arr[i]);
            larger.push_back(arr[i + 1]);
        } else {
            smaller.push_back(arr[i + 1]);
            larger.push_back(arr[i]);
        }
    }
    bool hasLeftover = (arr.size() % 2 != 0);
    int leftover;
    if (hasLeftover) {
        leftover = arr.back();
    }
    mergeInsertSortVector(larger);
    std::vector<int> jacob = generateJacobsthalSequence(smaller.size());
    std::vector<bool> inserted(smaller.size(), false);

    arr = larger;

    for (size_t j = 1; j < jacob.size(); ++j) {
        size_t index = jacob[j];
        if (index < smaller.size() && !inserted[index]) {
            insertIntoSortedVector(arr, smaller[index]);
            inserted[index] = true;
        }
    }
    for (size_t k = 0; k < smaller.size(); ++k) {
        if (!inserted[k])
            insertIntoSortedVector(arr, smaller[k]);
    }
    if (hasLeftover) {
        insertIntoSortedVector(arr, leftover);
    }
}

void PmergeMe::insertIntoSortedVector(std::vector<int>& arr, int value) {
    std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
    arr.insert(pos, value);
}



void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() < 2)
        return;

    std::deque<int> larger;
    std::deque<int> smaller;

    size_t i = 0;
    for (; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1]) {
            smaller.push_back(arr[i]);
            larger.push_back(arr[i + 1]);
        } else {
            smaller.push_back(arr[i + 1]);
            larger.push_back(arr[i]);
        }
    }

    bool hasLeftover = (arr.size() % 2 != 0);
    int leftover;
    if (hasLeftover) {
        leftover = arr.back();
    }

    mergeInsertSortDeque(larger);

    std::vector<int> jacob = generateJacobsthalSequence(smaller.size());
    std::vector<bool> inserted(smaller.size(), false);

    arr.assign(larger.begin(), larger.end());

    for (size_t j = 1; j < jacob.size(); ++j) {
        size_t index = jacob[j];
        if (index < smaller.size() && !inserted[index]) {
            insertIntoSortedDeque(arr, smaller[index]);
            inserted[index] = true;
        }
    }

    for (size_t k = 0; k < smaller.size(); ++k) {
        if (!inserted[k])
            insertIntoSortedDeque(arr, smaller[k]);
    }

    if (hasLeftover) {
        insertIntoSortedDeque(arr, leftover);
    }
}

void PmergeMe::insertIntoSortedDeque(std::deque<int>& arr, int value) {
    std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
    arr.insert(pos, value);
}


void PmergeMe::sortAndMeasureTime()
{
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
    std::cout << "Time to process a range of  " << _vector.size() << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of  " << _deque.size() << " elements with std::deque : " << timeDeque << " us" << std::endl;
}

