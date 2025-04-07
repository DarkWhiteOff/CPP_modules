#include "HumanB.hpp"

HumanB::HumanB(void)
{
    std::cout << "Human B born" << std::endl;
    return ;
}

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{
    std::cout << "Human B born" << std::endl;
    return ;
}

HumanB::~HumanB(void)
{
    std::cout << "Human B died" << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    if (weapon.getType().empty())
        m_weapon = NULL;
	else
        m_weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (m_weapon != NULL && m_weapon->getType() != "")
        std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
	else
        std::cout << m_name << " attacks without weapon" << std::endl;
}