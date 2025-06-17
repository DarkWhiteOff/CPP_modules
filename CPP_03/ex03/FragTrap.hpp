#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public :
    FragTrap(void);
    FragTrap(std::string Name);
    FragTrap(const FragTrap &copy);
    FragTrap &operator=(const FragTrap &src);
    ~FragTrap(void);
    void    attack(const std::string &target);
    void    highFivesGuys(void);

protected :
    static unsigned int const         m_init_hitPoints = 100;
    static unsigned int const         m_init_energyPoints = 100;
    static unsigned int const         m_init_attackDamage = 30;
};

#endif