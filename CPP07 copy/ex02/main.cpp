#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}


int main()
{
    try {
        Array<int> arr(5);
        
        for (unsigned int i = 0; i < arr.size(); ++i)
        {
            arr[i] = i * 10;
        }

        std::cout << "arr: ";
        for (unsigned int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr_copy = arr;
        std::cout << "arr_copy: ";
        for (unsigned int i = 0; i < arr_copy.size(); ++i) {
            std::cout << arr_copy[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr_assign;
        arr_assign = arr;
        std::cout << "arr_assign: ";
        for (unsigned int i = 0; i < arr_assign.size(); ++i) {
            std::cout << arr_assign[i] << " ";
        }
        std::cout << std::endl;
        std::cout << arr[10] << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}

