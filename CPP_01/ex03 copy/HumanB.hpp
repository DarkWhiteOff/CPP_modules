#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class   HumanB
{
public :
    HumanB(void);
    HumanB(std::string name);
    ~HumanB(void);
    void    setWeapon(Weapon weapon);
    void    attack(void);

private :
    std::string m_name;
    Weapon  m_weapon;
};

#endif