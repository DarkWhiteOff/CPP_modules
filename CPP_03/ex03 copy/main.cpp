#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap Kanye("Kanye");
    ScavTrap Ye("Ye");
    FragTrap Elon("Elon");
    DiamondTrap Diddy("Diddy");
    
    Kanye.attack("Ye");
    Ye.takeDamage(0);
    Ye.beRepaired(0);
    Ye.attack("Kanye");
    Kanye.takeDamage(20);
    Kanye.beRepaired(15);
    Elon.attack("Kanye");
    Kanye.takeDamage(30);
    return (0);
}