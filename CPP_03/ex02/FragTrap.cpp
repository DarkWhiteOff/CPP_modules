#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "(Fragtrap) Default consttrucor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy.m_Name)
{
    m_hitPoints = copy.m_hitPoints;
    m_energyPoints = copy.m_energyPoints;
    m_attackDamage = copy.m_attackDamage;
    std::cout << "(Fragtrap) Copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "(Fragtrap) Surcharged constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
    std::cout << "(Fragtrap) Copy assignment operator called" << std::endl;
    ClapTrap(src.m_Name);
    m_hitPoints = src.m_hitPoints;
    m_energyPoints = src.m_energyPoints;
    m_attackDamage = src.m_attackDamage;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    // ~ClapTrap(); ??
    std::cout << "(Fragtrap) Destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Hey guys! High five!!!" << std::endl;
}