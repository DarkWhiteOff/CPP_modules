#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return ;
}

Weapon::Weapon(std::string type) : m_type(type)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

const std::string &Weapon::getType(void)
{
    return (m_type);
}

void    Weapon::setType(std::string new_type)
{
    m_type = new_type;
}