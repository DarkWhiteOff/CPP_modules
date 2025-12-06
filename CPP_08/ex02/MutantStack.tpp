#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
    return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    (*this) = copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
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
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

#endif