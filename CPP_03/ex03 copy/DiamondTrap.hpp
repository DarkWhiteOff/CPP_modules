#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public :
    DiamondTrap(void);
    DiamondTrap(const DiamondTrap& copy);
    DiamondTrap(std::string Name);
    DiamondTrap& operator=(const DiamondTrap& src);
    ~DiamondTrap(void);
    using   ScavTrap::attack;
    void    whoAmI(void);

private :
    std::string clap_Name;
};

#endif