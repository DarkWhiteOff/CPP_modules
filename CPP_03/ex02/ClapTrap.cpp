#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : m_Name("Default"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "Default consttrucor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : m_Name(Name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "Surcharged constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : m_Name(copy.m_Name), m_hitPoints(copy.m_hitPoints), m_energyPoints(copy.m_energyPoints), m_attackDamage(copy.m_attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_Name = src.m_Name;
        m_hitPoints = src.m_hitPoints;
        m_energyPoints = src.m_energyPoints;
        m_attackDamage = src.m_attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << m_Name << " has no energy left to attack.";
        if (m_hitPoints <= 0)
            std::cout << " (no hit points left as well).";
        std::cout << std::endl;
		return ;
    }
    else if (m_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << m_Name << " has no hit points left to attack." << std::endl;
		return ;
    }
    else
    {
        std::cout << "ClapTrap " << m_Name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << std::endl;
        m_energyPoints--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (m_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << m_Name << " is already dead..." << std::endl;
        return ;
    }
    std::cout << "Claptrap " << m_Name << " took " << amount << " points of damage!" << std::endl;
    m_hitPoints -= amount;
    if (m_hitPoints <= 0)
        std::cout << "ClapTrap " << m_Name << " passed away." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << m_Name << " has no energy left to repair itself.";
        if (m_hitPoints <= 0)
            std::cout << " (no hit points left as well).";
        std::cout << std::endl;
		return ;
    }
    else if (m_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << m_Name << " has no hit points left to repair itself." << std::endl;
		return ;
    }
    else
    {
        std::cout << "Claptrap " << m_Name << " repaired itself using 1 energy point!" << std::endl;
        m_hitPoints += amount;
        m_energyPoints--;
    }
}

unsigned int ClapTrap::getApts(void)
{
    std::cout << m_attackDamage << std::endl;
    return (m_attackDamage);
}

unsigned int ClapTrap::getHpts(void)
{
    std::cout << m_hitPoints << std::endl;
    return (m_hitPoints);
}

unsigned int ClapTrap::getEpts(void)
{
    std::cout << m_energyPoints << std::endl;
    return (m_energyPoints);
}