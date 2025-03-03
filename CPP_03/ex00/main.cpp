#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Kanye("Kanye");
    ClapTrap Ye("Ye");
    
    Kanye.attack("Ye");
    Ye.takeDamage(0);
    Ye.beRepaired(0);
    Ye.attack("Kanye");
    Kanye.takeDamage(0);
    return (0);
}