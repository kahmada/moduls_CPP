#include "Span.hpp"

Span::Span() : _n(0), _vec(0){}


Span::Span(unsigned int n) : _n(n) , _vec(0){}

Span::Span(const Span &src) {
    *this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        _n = rhs._n;
        _vec = rhs._vec;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_vec.size() >= _n)
        throw SpanFullException();
    _vec.push_back(n);
}

int Span::shortestSpan() const {
    if (_vec.size() <= 1)
        throw NotEnoughElementsException(); 

    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());

    int min = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++) {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

int Span::longestSpan() const {
    if (_vec.size() <= 1)
        throw NotEnoughElementsException();

    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return max - min;
}

const char *Span::SpanFullException::what() const throw() {
    return "Cannot add more numbers.";
}

const char *Span::NotEnoughElementsException::what() const throw() {
    return "Not enough elements";
}

