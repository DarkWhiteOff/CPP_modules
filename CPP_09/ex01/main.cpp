#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <stack>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn(argv[1]);
        rpn.calc();
    }
    catch (std::exception &o)
    {
        std::cerr << o.what() << std::endl;
    }
    return (0);
}