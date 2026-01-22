#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

template <typename T>
void easyfind(T &c, int occ);

class NoOccurenceFound : public std::exception
{
    public :
        virtual const char *what(void) const throw();
};

#include "easyfind.tpp"

#endif