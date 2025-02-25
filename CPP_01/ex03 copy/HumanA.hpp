#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"


class   HumanA
{
public :
    HumanA(void);
    HumanA(std::string name, Weapon weapon);
    ~HumanA(void);
    void    attack(void);

private :
    std::string m_name;
    Weapon  m_weapon;
};

#endif