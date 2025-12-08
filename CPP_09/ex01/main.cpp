#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <sstream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Invalid number of arguments." << std::endl;
        return (1);
    }
    try
    {
        RPN rpn(argv[1]);
        rpn.calc();
    }
    catch (std::exception &o)
    {
        std::cout << o.what() << std::endl;
    }
    return (0);
}