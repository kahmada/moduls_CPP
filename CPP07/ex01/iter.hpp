
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
    if (array == NULL || func == NULL)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}


template <typename T>
void iter(T *array, size_t length, void (*func)(const T &))
{
    if (array == NULL || func == NULL)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
