#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public :
    ClapTrap(void);
    ClapTrap(const ClapTrap& copy);
    ClapTrap(std::string Name);
    ClapTrap& operator=(const ClapTrap& copy);
    ~ClapTrap(void);
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

private :
    std::string m_Name;
    int         m_hitPoints;
    int         m_energyPoints;
    int         m_attackDamage;
};

#endif