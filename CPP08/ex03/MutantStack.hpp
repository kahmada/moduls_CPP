#pragma once

#include <stack>
#include <iterator>

#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(MutantStack const &mutantStack) : std::stack<T>(mutantStack) {}
    MutantStack &operator=(MutantStack const &rhs)
    {
        if (this != &rhs) {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
};
