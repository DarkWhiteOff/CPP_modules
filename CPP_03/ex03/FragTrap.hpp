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
    FragTrap& operator=(const FragTrap& src);
    ~FragTrap(void);
    void    highFivesGuys(void);
};

#endif