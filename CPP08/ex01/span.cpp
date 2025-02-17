#include "span.hpp"

Span::Span(unsigned int n) : _n(n) {}

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

int Span::shortestSpan() const {  // Trouve la plus petite différence entre deux nombres.
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

int Span::longestSpan() const {//la difference entre le plus grand et le plus putit 
    if (_vec.size() <= 1)
        throw NotEnoughElementsException();

    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return max - min;
}

void Span::fillSpanRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _vec.size() > _n)
        throw SpanFullException();
    _vec.insert(_vec.end(), begin, end);
}

const char *Span::SpanFullException::what() const throw() {
    return "Span is full! Cannot add more numbers.";
}

const char *Span::NotEnoughElementsException::what() const throw() {
    return "Not enough elements to calculate a span!";
}

