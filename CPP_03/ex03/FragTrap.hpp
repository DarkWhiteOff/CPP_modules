#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public :
    FragTrap(void);
    FragTrap(const FragTrap& copy);
    FragTrap(std::string Name);
    FragTrap& operator=(const FragTrap& copy);
    ~FragTrap(void);
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    highFivesGuys(void);
   
private :
    std::string m_Name;
    int         m_hitPoints;
    int         m_energyPoints;
    int         m_attackDamage;
};

#endif