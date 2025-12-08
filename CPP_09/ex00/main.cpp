#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange b;
        b.make(argv[1]);
    }
    catch (std::exception &o)
    {
        std::cout << o.what() << std::endl;
    }
    return (0);
}