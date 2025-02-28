#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap
{
public :
    ScavTrap(void);
    ScavTrap(const ScavTrap& copy);
    ScavTrap(std::string Name);
    ScavTrap& operator=(const ScavTrap& copy);
    ~ScavTrap(void);
    void    attack(const std::string& target);
    // void    takeDamage(unsigned int amount);
    // void    beRepaired(unsigned int amount);



private :
    std::string m_Name;
    int         m_hitPoints;
    int         m_energyPoints;
    int         m_attackDamage;
};

#endif