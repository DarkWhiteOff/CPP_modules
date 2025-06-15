#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public :
    ScavTrap(void);
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(const ScavTrap &src);
    ~ScavTrap(void);
    void    attack(const std::string &target);
    void    guardGate(void);
};

#endif