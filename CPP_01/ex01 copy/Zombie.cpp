#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::Zombie(std::string n) : m_name(n)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << m_name << " destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << m_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}