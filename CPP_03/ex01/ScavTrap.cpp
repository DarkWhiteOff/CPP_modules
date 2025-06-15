#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "(ScavTrap) Default construcor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    m_Name = Name;
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "(ScavTrap) Surcharged constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    m_Name = copy.m_Name;
    m_hitPoints = copy.m_hitPoints;
    m_energyPoints = copy.m_energyPoints;
    m_attackDamage = copy.m_attackDamage;
    std::cout << "(ScavTrap) Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "(ScavTrap) Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_Name = src.m_Name;
        m_hitPoints = src.m_hitPoints;
        m_energyPoints = src.m_energyPoints;
        m_attackDamage = src.m_attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "(ScavTrap) Destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << m_Name << " has no energy left to attack.";
        if (m_hitPoints <= 0)
            std::cout << " (no hit points left as well).";
        std::cout << std::endl;
		return ;
    }
    else if (m_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << m_Name << " has no hit points left to attack." << std::endl;
		return ;
    }
    else
    {
        std::cout << "ScavTrap " << m_Name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        m_energyPoints--;
    }
}

void    ScavTrap::guardGate(void)
{
    if (m_hitPoints <= 0)
        return ;
    std::cout << "ScavTrap " << m_Name << " is now in gate keeper mode." << std::endl;
}
