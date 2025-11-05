#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <sstream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    try
    {
        RPN rpn(argv[1]);
        rpn.calc();
    }
    catch (std::exception &o)
    {
        std::cout << o.what() << std::endl;
    }
}