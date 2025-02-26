#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    Harl goat;

    goat.complain(argv[1]);
    return (0);
}