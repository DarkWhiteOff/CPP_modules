#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 100;
    FragTrap::m_attackDamage = 30;
    std::cout << "(Fragtrap) Default consttrucor called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    m_Name = Name;
    m_hitPoints = 100;
    m_energyPoints = 100;
    FragTrap::m_attackDamage = 30;
    std::cout << "(Fragtrap) Surcharged constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    m_Name = copy.m_Name;
    m_hitPoints = copy.m_hitPoints;
    m_energyPoints = copy.m_energyPoints;
    m_attackDamage = copy.m_attackDamage;
    std::cout << "(Fragtrap) Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "(Fragtrap) Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_Name = src.m_Name;
        m_hitPoints = src.m_hitPoints;
        m_energyPoints = src.m_energyPoints;
        m_attackDamage = src.m_attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "(Fragtrap) Destructor called" << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "Fragtrap " << m_Name << " has no energy left to attack.";
        if (m_hitPoints <= 0)
            std::cout << " (no hit points left as well).";
        std::cout << std::endl;
		return ;
    }
    else if (m_hitPoints <= 0)
    {
        std::cout << "Fragtrap " << m_Name << " has no hit points left to attack." << std::endl;
		return ;
    }
    else
    {
        std::cout << "Fragtrap " << m_Name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        m_energyPoints--;
    }
}

void    FragTrap::highFivesGuys(void)
{
    if (m_hitPoints <= 0)
        return ;
    std::cout << "Hey guys! High five!!!" << std::endl;
}