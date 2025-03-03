#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "(ScavTrap) Default consttrucor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy.m_Name)
{
    m_hitPoints = copy.m_hitPoints;
    m_energyPoints = copy.m_energyPoints;
    m_attackDamage = copy.m_attackDamage;
    std::cout << "(ScavTrap) Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "(ScavTrap) Surcharged constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    std::cout << "(ScavTrap) Copy assignment operator called" << std::endl;
    ClapTrap(src.m_Name);
    m_hitPoints = src.m_hitPoints;
    m_energyPoints = src.m_energyPoints;
    m_attackDamage = src.m_attackDamage;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    // ~ClapTrap(); ??
    std::cout << "(ScavTrap) Destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (m_hitPoints >= 0 && m_energyPoints >= 0)
    {
        std::cout << "ScavTrap " << m_Name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        m_energyPoints--;
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << m_Name << " is now in gate keeper mode." << std::endl;
}
