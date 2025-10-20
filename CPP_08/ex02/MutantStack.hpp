#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack
{
public :
    MutantStack(void);
    MutantStack(const MutantStack &copy);
    MutantStack &operator=(const MutantStack &src);
    ~MutantStack(void);


};

#endif