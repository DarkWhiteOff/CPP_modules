#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
    m_array = new T[0];
    m_l = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    m_array = new T[n];
    m_l = n;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    m_array = new T[copy.m_l];
    m_l = copy.m_l;
    for (int i = 0; i < m_l; i++)
        m_array[i] = copy.m_array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    if (this != &src)
    {
        m_array = new T[src.m_l];
        m_l = src.m_l;
        for (int i = 0; i < m_l; i++)
            m_array[i] = src.m_array[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](const int i)
{
    if (i < 0 || i >= m_l)
        throw IndexOutOfBounds();
    return (m_array[i]);
}

template <typename T>
Array<T>::~Array(void)
{
    return ;
}

template <typename T>
int Array<T>::size(void)
{
    return (m_l);
}

template <typename T>
const char *Array<T>::IndexOutOfBounds::what(void) const throw()
{
    return ("Index Out Of Bounds!\n");
}

#endif