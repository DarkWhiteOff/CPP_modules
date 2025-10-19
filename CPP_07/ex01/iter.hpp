#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, int l, void (*f)(T &))
{
    for (int i = 0; i < l; i++)
    {
        f(array[i]);
    }
}

#endif