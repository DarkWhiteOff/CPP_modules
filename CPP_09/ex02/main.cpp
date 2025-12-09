#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe p(argv);
        p.make();
    }
    catch (std::exception &o)
    {
        std::cerr << o.what() << std::endl;
    }
}

// Provide tests