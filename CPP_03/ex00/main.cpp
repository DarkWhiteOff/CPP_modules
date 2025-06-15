#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Walter("Walter");
    ClapTrap Jesse("Jesse");
    
    Walter.attack("Jesse"); // first attack
    Jesse.takeDamage(0);
    Jesse.beRepaired(0);
    Jesse.attack("Walter");
    Walter.takeDamage(0);
    Walter.attack("Jesse"); // 2
    Walter.attack("Jesse"); // 3
    Walter.attack("Jesse"); // 4
    Walter.attack("Jesse"); // 5
    Walter.attack("Jesse"); // 6
    Walter.attack("Jesse"); // 7
    Walter.attack("Jesse"); // 8
    Walter.attack("Jesse"); // 9
    Walter.attack("Jesse"); // 10
    Walter.attack("Jesse"); // 11 -> no energy left
    return (0);
}