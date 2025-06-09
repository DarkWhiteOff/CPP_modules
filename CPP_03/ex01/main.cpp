#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap Kanye("Kanye");
    ScavTrap Ye("Ye");
    
    Kanye.attack("Ye");
    Ye.takeDamage(0);
    Ye.beRepaired(0);
    Ye.attack("Kanye");
    Kanye.takeDamage(20);
    return (0);
}