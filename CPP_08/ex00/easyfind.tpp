#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include "easyfind.hpp"

template <typename T>
void    easyfind(T &c, int occ)
{
    typename T::iterator it = std::find(c.begin(), c.end(), occ);
    if (it == c.end())
        throw NoOccurenceFound();
}

const char *NoOccurenceFound::what(void) const throw()
{
    return ("No Occurence Found!");
}

#endif