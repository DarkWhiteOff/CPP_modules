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
};

#endif