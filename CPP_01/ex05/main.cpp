#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl goat;
    
    (void)argc;
    goat.complain(argv[1]);
    return (0);
}