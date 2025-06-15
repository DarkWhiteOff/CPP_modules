#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap Walter("Walter");
    ScavTrap Jesse("Jesse");
    FragTrap Mike("Mike");
    
    Walter.attack("Jesse"); // first attack
    Jesse.takeDamage(0);
    Jesse.beRepaired(0); // -1 Epts
    Jesse.attack("Walter"); // -1 Epts
    Walter.takeDamage(20);
    Walter.attack("Jesse"); // 2 -> no hit points left
    Jesse.attack("Mike");
    Mike.takeDamage(20);
    Mike.attack("Jesse");
    Jesse.takeDamage(30);
    Mike.highFivesGuys();
    Jesse.attack("Mike");
    Jesse.attack("Mike");
    Jesse.attack("Mike");
    Jesse.attack("Mike");
    Mike.takeDamage(20);
    Mike.takeDamage(20);
    Mike.takeDamage(20);
    Mike.takeDamage(20);
    return (0);
}