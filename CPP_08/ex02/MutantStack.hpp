#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public :
    MutantStack(void);
    MutantStack(MutantStack const &copy);
    MutantStack &operator=(MutantStack const &src);
    ~MutantStack(void);

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif