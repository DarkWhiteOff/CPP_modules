#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{

private :
    std::string m_Name;
    //ClapTrap::name??
    int         m_hitPoints;
    int         m_energyPoints;
    int         m_attackDamage;
};

#endif