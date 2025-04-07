#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    Harl goat;

    if (argc == 2)
        goat.complain(argv[1]);
    else
        std::cout << "Wrong arguments." << std::endl;
    return (0);
}