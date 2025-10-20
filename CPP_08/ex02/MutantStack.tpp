#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
    return ;
}

template <typename T>
MutantStack<T>::MutantStack(unsigned int N)
{
    return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    *this = copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    if (this != &src)
    {
        
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
    return ;
}

template <typename T>
const char *MutantStack<T>::SpanIsFullException::what(void) const throw()
{
    return ("Span Is Full!\n");
}

#endif