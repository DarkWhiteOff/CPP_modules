#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : m_Name(), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "Default consttrucor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : m_Name(copy.m_Name), m_hitPoints(copy.m_hitPoints), m_energyPoints(copy.m_energyPoints), m_attackDamage(copy.m_attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : m_Name(Name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "Surcharged constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    m_Name = copy.m_Name;
    m_hitPoints = copy.m_hitPoints;
    m_energyPoints = copy.m_energyPoints;
    m_attackDamage = copy.m_attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (m_hitPoints <= 0 || m_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << m_Name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        target.takeDamage(m_attackDamage); // pas sur pour target.
        m_energyPoints--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "Claptrap " << m_Name << " took " << amount << " points of damage!" << std::endl;
    m_hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (m_hitPoints <= 0 || m_energyPoints <= 0)
    {
        std::cout << "Claptrap " << m_Name << " repaired itself using 1 energy point!" << std::endl;
        m_hitPoints += amount;
        m_energyPoints--;
    }
}