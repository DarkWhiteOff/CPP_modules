#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    // ClapTrap Walter("Walter");
    // ScavTrap Jesse("Jesse");
    // FragTrap Mike("Mike");
    DiamondTrap Saul;
    
    // Walter.attack("Jesse"); // first attack
    // Jesse.takeDamage(0);
    // Jesse.beRepaired(0); // -1 Epts
    // Jesse.attack("Walter"); // -1 Epts
    // Walter.takeDamage(20);
    // Walter.attack("Jesse"); // 2 -> no hit points left
    // Jesse.attack("Mike");
    // Mike.takeDamage(20);
    // Mike.attack("Jesse");
    // Jesse.takeDamage(30);
    // Saul.attack("Jesse");
    // Saul.attack("Jesse");
    // Saul.attack("Jesse");
    // Jesse.takeDamage(30);
    // Jesse.takeDamage(30);
    // Jesse.takeDamage(30);
    
    Saul.whoAmI();
    return (0);
}