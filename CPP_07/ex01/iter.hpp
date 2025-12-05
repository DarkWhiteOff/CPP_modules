#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t const size, void (*f)(T &))
{
    if (!array || !f || size <= 0)
        return ;
    for (size_t i = 0; i < size; ++i)
        f(array[i]);
}

template <typename T>
void iter(T const *array, size_t const size, void (*f)(T const &))
{
    if (!array || !f || size <= 0)
        return ;
    for (size_t i = 0; i < size; ++i)
        f(array[i]);
}

#endif