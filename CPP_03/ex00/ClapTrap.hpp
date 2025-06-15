#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public :
    ClapTrap(void);
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &src);
    ~ClapTrap(void);
    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    unsigned int getApts(void);
    unsigned int getHpts(void);
    unsigned int getEpts(void);

private :
    std::string m_Name;
    int         m_hitPoints;
    int         m_energyPoints;
    int         m_attackDamage;
};

#endif