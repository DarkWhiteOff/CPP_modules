#include "HumanA.hpp"

HumanA::HumanA(void)
{
    return ;
}

HumanA::HumanA(std::string name, Weapon weapon) : m_name(name), m_weapon(weapon)
{
    return ;
}

HumanA::~HumanA(void)
{
    return ;
}

void    HumanA::attack(void)
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}