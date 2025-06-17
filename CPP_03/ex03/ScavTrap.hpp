#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public :
    ScavTrap(void);
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(const ScavTrap &src);
    ~ScavTrap(void);
    void    attack(const std::string &target);
    void    guardGate(void);

protected :
    static unsigned int const         m_init_hitPoints = 100;
    static unsigned int const         m_init_energyPoints = 50;
    static unsigned int const         m_init_attackDamage = 20;
};

#endif