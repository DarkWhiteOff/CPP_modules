#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
    return ;
}

HumanA::~HumanA(void)
{
    return ;
}

void    HumanA::attack(void)
{
    if (m_weapon.getType().empty())
	{
		std::cout << m_name << " attacks without weapon" << std::endl;
		return;
	}
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}