#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap Walter("Walter");
    ScavTrap Jesse("Jesse");
    
    Walter.attack("Jesse"); // first attack
    Jesse.takeDamage(0);
    Jesse.beRepaired(0); // -1 Epts
    Jesse.attack("Walter"); // -1 Epts
    Walter.takeDamage(20);
    Walter.attack("Jesse"); // 2 -> no hit points left
    Jesse.guardGate();
    for (int i = 48; i > 0; i--)
        Jesse.beRepaired(1); // -48 Epts
    Jesse.beRepaired(1); // no energy
    return (0);
}