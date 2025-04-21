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


std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<int> seq = {0, 1}; 

    while (true) {
        int nextValue = seq.back() + 2 * seq[seq.size() - 2];  // J(n) = J(n-1) + 2*J(n-2)
        if (nextValue >= static_cast<int>(size)) break;  // Stoppe, wenn größer als 'size'
        seq.push_back(nextValue);
    }

    return seq;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    if (arr.size() < 2)
        return;

    std::vector<int> larger;
    std::vector<int> smaller;

    // Step 1: Pair and split
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

    // If odd size, remember the last element
    bool hasLeftover = (arr.size() % 2 != 0);
    int leftover = hasLeftover ? arr.back() : 0;

    // Step 2: Recursively sort the larger elements
    mergeInsertSortVector(larger);

    // Step 3: Insert smaller elements in Jacobsthal order
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

    // Insert remaining smaller elements not covered by Jacobsthal sequence
    for (size_t k = 0; k < smaller.size(); ++k) {
        if (!inserted[k])
            insertIntoSortedVector(arr, smaller[k]);
    }

    // Step 4: Insert leftover if it existed
    if (hasLeftover) {
        insertIntoSortedVector(arr, leftover);
    }
}

void PmergeMe::insertIntoSortedVector(std::vector<int>& arr, int value) {
    std::vector<int>::iterator it = arr.begin();
    while (it != arr.end() && *it < value) {
        ++it;
    }
    arr.insert(it, value);
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
    int leftover = hasLeftover ? arr.back() : 0;

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
    std::deque<int>::iterator it = arr.begin();
    while (it != arr.end() && *it < value) {
        ++it;
    }
    arr.insert(it, value);
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


void PmergeMe::sortAndMeasureTime()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    // Mesurer le temps de traitement pour trier _vector avec mergeInsertSort
    clock_t startVector = clock(); // Capture l'heure avant de commencer le tri sur _vector
    mergeInsertSortVector(_vector); // Appelle la fonction de tri sur _vector
    clock_t endVector = clock(); // Capture l'heure après que le tri sur _vector est terminé

    // Calculer le temps écoulé pour trier _vector en microsecondes
    double timeVector = (double)(endVector - startVector) / CLOCKS_PER_SEC * 1000000;


    clock_t startDeque = clock();
    mergeInsertSortDeque(_deque);
    clock_t endDeque = clock();

    double timeDeque = (double)(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    // Afficher le contenu de _vector après le tri
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " "; // Affiche chaque élément de _vector après le tri
    }
    std::cout << std::endl;

    // Afficher les résultats des temps de traitement pour _vector et _deque
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << timeDeque << " us" << std::endl;
}

