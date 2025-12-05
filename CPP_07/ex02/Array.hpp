#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
public :
    Array(void);
    Array(unsigned int n);
    Array(Array const &copy);
    Array &operator=(Array const &src);
    ~Array(void);

    T operator[](unsigned int index) const;
    T &operator[](unsigned int index);

    unsigned int getSize(void) const;

    class IndexOutOfBounds : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    unsigned int m_size;
    T *m_array;
};

#include "Array.tpp"

#endif