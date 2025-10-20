#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
void    easyfind(T c, int occ);

class NoOccurenceFound : public std::exception
{
    public :
        virtual const char *what(void) const throw();
};

#endif