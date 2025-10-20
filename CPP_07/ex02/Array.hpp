#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
public :
    Array(void);
    Array(unsigned int n);
    Array(const Array &copy);
    Array &operator=(const Array &src);
    T &operator[](const int i);
    ~Array(void);

    int size(void);

    class IndexOutOfBounds : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    T *m_array;
    unsigned int m_l;
};

#endif