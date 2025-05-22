#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    unsigned int size() const;
    ~Array();
};
#endif
