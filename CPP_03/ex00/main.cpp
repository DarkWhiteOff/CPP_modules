#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Walter("Walter");
    ClapTrap Jesse("Jesse");
    ClapTrap Test("Test");
    
    Walter.attack("Jesse"); // first attack
    Jesse.takeDamage(0);
    Jesse.beRepaired(1);
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
    Jesse.takeDamage(5);
    Jesse.takeDamage(5);
    Jesse.takeDamage(1); // -> no hit points left
    Jesse.attack("Walter"); // -> cannot attack
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1);
    Test.beRepaired(1); // -> no energy left
    return (0);
}