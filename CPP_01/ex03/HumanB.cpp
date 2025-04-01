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

void    HumanB::setWeapon(Weapon &weapon)
{
    m_weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (m_weapon->getType().empty())
	{
		std::cout << m_name << " attacks without weapon" << std::endl;
		return;
	}
    std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}