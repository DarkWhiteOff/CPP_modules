#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : m_Name(), m_hitPoints(100), m_energyPoints(50), m_attackDamage(20)
{
    std::cout << "Default consttrucor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : m_Name(copy.m_Name), m_hitPoints(copy.m_hitPoints), m_energyPoints(copy.m_energyPoints), m_attackDamage(copy.m_attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : m_Name(Name), m_hitPoints(100), m_energyPoints(50), m_attackDamage(20)
{
    std::cout << "Surcharged constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    m_Name = copy.m_Name;
    m_hitPoints = copy.m_hitPoints;
    m_energyPoints = copy.m_energyPoints;
    m_attackDamage = copy.m_attackDamage;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (m_hitPoints <= 0 || m_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << m_Name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        target.takeDamage(m_attackDamage); // pas sur pour target.
        m_energyPoints--;
    }
}

// void    ClapTrap::takeDamage(unsigned int amount)
// {
//     std::cout << "Claptrap " << m_Name << " took " << amount << " points of damage!" << std::endl;
//     m_hitPoints -= amount;
// }

// void    ClapTrap::beRepaired(unsigned int amount)
// {
//     if (m_hitPoints <= 0 || m_energyPoints <= 0)
//     {
//         std::cout << "Claptrap " << m_Name << " repaired itself using 1 energy point!" << std::endl;
//         m_hitPoints += amount;
//         m_energyPoints--;
//     }
// }

