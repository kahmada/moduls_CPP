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
        Span(unsigned int n);  // Suppression du constructeur par défaut
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &rhs);

        // Méthodes principales
        void addNumber(int n);
        int shortestSpan() const;  // Ajout de const
        int longestSpan() const;   // Ajout de const
        void fillSpanRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        // Exceptions
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
