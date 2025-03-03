#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
    FragTrap::m_hitPoints = 100;
    ScavTrap::m_energyPoints = 50;
    FragTrap::m_attackDamage = 30;
    std::cout << "(DiamondTrap) Default consttrucor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : FragTrap(), ScavTrap()
{
    clap_Name = copy.clap_Name;
    FragTrap::m_Name = copy.FragTrap::m_Name;
    FragTrap::m_hitPoints = copy.FragTrap::m_hitPoints;
    ScavTrap::m_energyPoints = copy.ScavTrap::m_energyPoints;
    FragTrap::m_attackDamage = copy.FragTrap::m_attackDamage;
    std::cout << "(DiamondTrap) Copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : FragTrap(Name), ScavTrap(Name)
{
    clap_Name = Name += "_clap_name";
    FragTrap::m_hitPoints = 100;
    ScavTrap::m_energyPoints = 50;
    FragTrap::m_attackDamage = 30;
    std::cout << "(DiamondTrap) Surcharged constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
    std::cout << "(DiamondTrap) Copy assignment operator called" << std::endl;
    clap_Name = src.clap_Name;
    FragTrap::m_Name = src.FragTrap::m_Name;
    FragTrap::m_hitPoints = src.FragTrap::m_hitPoints;
    ScavTrap::m_energyPoints = src.ScavTrap::m_energyPoints;
    FragTrap::m_attackDamage = src.FragTrap::m_attackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    // ~ScavTrap(); ??
    // ~FragTrap(); ??
    std::cout << "(DiamondTrap) Destructor called" << std::endl;
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << FragTrap::m_Name << " and my ClapTrap name is " << clap_Name << std::endl;
}