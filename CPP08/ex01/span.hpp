#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &rhs);

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
        void fillSpanRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        class SpanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NotEnoughElementsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};


