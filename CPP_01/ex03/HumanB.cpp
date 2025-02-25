#include "HumanB.hpp"

HumanB::HumanB(void)
{
    return ;
}

HumanB::HumanB(std::string name) : m_name(name)
{
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void    HumanB::setWeapon(Weapon weapon)
{
    m_weapon = weapon;
}

void    HumanB::attack(void)
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}