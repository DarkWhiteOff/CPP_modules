#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <algorithm>
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
    return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &copy) : std::stack<T>(copy)
{
    return ;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src)
{
    if (this != &src)
    {
        std::stack<T>::operator=(src);
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
    return ;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

#endif