#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
    std::cout << "Human A born" << std::endl;
    return ;
}

HumanA::~HumanA(void)
{
    std::cout << "Human A died" << std::endl;
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