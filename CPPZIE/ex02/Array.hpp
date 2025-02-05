#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    Array() : _array(NULL), _size(0) {}

    Array(unsigned int n) : _size(n) {
        if (n > 0) {
            _array = new T[n];
        } else {
            _array = NULL;
        }
    }

    Array(const Array<T>& other) : _size(other._size) {
        if (_size > 0) {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _array[i] = other._array[i];
            }
        } else {
            _array = NULL;
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            // Libérer l'ancienne mémoire
            delete[] _array;

            _size = other._size;
            if (_size > 0) {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; ++i) {
                    _array[i] = other._array[i];
                }
            } else {
                _array = NULL;
            }
        }
        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::exception();  // Lancer une exception si l'index est hors limites
        }
        return _array[index];
    }

    unsigned int size() const {
        return _size;
    }
    ~Array() {
        delete[] _array;
    }
};

#endif
