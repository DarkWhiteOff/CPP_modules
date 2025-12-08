#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: Not enough arguments." << std::endl;
        return (1);
    }
    try
    {
        PmergeMe p(argv);
        p.make();
    }
    catch (std::exception &o)
    {
        std::cout << o.what() << std::endl;
    }
}