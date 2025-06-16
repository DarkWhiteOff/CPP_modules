#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public :
    DiamondTrap(void);
    DiamondTrap(std::string Name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap &operator=(const DiamondTrap &src);
    ~DiamondTrap(void);
    void	attack(const std::string &target);
    void    whoAmI(void);

private :
    std::string m_Name;
};

#endif