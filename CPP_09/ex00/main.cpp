#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    try
    {
        BitcoinExchange b;
        b.make(argv[1]);
    }
    catch (std::exception &o)
    {
        std::cout << o.what() << std::endl;
    }
}