#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

template <typename T>
void    easyfind(T c, int occ)
{
    T::iterator it = std::find(c.begin(), c.end(), occ);
    if (it == c.end())
        throw NoOccurenceFound();
    else
        std::cout << "Value : " << occ << " was found at position : " << *it << std::endl;
}

const char *NoOccurenceFound::what(void) const throw()
{
    return ("No Occurence Found!\n");
}

#endif