#include "FragTrap.hpp"

FragTrap::FragTrap(void) : m_Name(), m_hitPoints(100), m_energyPoints(100), m_attackDamage(30)
{
    std::cout << "(Fragtrap) Default consttrucor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : m_Name(copy.m_Name), m_hitPoints(copy.m_hitPoints), m_energyPoints(copy.m_energyPoints), m_attackDamage(copy.m_attackDamage)
{
    std::cout << "(Fragtrap) Copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : m_Name(Name), m_hitPoints(100), m_energyPoints(100), m_attackDamage(30)
{
    std::cout << "(Fragtrap) Surcharged constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "(Fragtrap) Copy assignment operator called" << std::endl;
    m_Name = copy.m_Name;
    m_hitPoints = copy.m_hitPoints;
    m_energyPoints = copy.m_energyPoints;
    m_attackDamage = copy.m_attackDamage;
    return (*this);
}

FragTrap::~ClapTrap(void)
{
    std::cout << "(Fragtrap) Destructor called" << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (m_hitPoints >= 0 && m_energyPoints >= 0)
    {
        std::cout << "Fragtrap " << m_Name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        m_energyPoints--;
    }
    else
        std::cout << "Not enough energy points or hit points!" << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "Fragtrap " << m_Name << " took " << amount << " points of damage!" << std::endl;
    m_hitPoints -= amount;
}

void    FragTrap::beRepaired(unsigned int amount)
{
    if (m_hitPoints >= 0 && m_energyPoints >= 0)
    {
        std::cout << "Fragtrap " << m_Name << " repaired itself using 1 energy point!" << std::endl;
        m_hitPoints += amount;
        m_energyPoints--;
    }
    else
        std::cout << "Not enough energy points or hit points!" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Hey guys! High five!!!" << std::endl;
}