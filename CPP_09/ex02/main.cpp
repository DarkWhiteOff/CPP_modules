#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    try
    {
        PmergeMe PmM();
        rpn.calc();
    }
    catch (std::exception &o)
    {
        std::cout << o.what() << std::endl;
    }
}