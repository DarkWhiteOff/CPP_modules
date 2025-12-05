#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : m_size(0), m_array(NULL)
{
    if (m_size > 0)
        m_array = new T[m_size]();
}

template <typename T>
Array<T>::Array(unsigned int n) : m_size(n), m_array(NULL)
{
    if (m_size > 0)
        m_array = new T[m_size]();
}

template <typename T>
Array<T>::Array(Array const &copy) : m_size(copy.m_size), m_array(NULL)
{
    (*this) = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
    if (this != &src)
    {
        if (m_array)
		    delete [] m_array;
        if (src.getSize() > 0)
        {
            m_size = src.m_size;
            m_array = new T[m_size];
            for (unsigned int i = 0; i < m_size; i++)
                m_array[i] = src.m_array[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    if (m_array)
        delete [] m_array;
}

template <typename T>
T Array<T>::operator[](unsigned int index) const
{
    if (index >= m_size || !m_array)
        throw IndexOutOfBounds();
    return (m_array[index]);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= m_size || !m_array)
        throw IndexOutOfBounds();
    return (m_array[index]);
}

template <typename T>
unsigned int Array<T>::getSize(void) const
{
    return (m_size);
}

template <typename T>
const char *Array<T>::IndexOutOfBounds::what(void) const throw()
{
    return ("Index Out Of Bounds!\n");
}

#endif