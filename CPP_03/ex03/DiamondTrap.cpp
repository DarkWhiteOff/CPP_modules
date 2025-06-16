#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
    std::cout << "(DiamondTrap) Default construcor called" << std::endl;
    FragTrap::m_hitPoints = 100;
    ScavTrap::m_energyPoints = 50;
    FragTrap::m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string Name) : FragTrap(Name), ScavTrap(Name)
{
    std::cout << "(DiamondTrap) Surcharged constructor called" << std::endl;
    m_Name = Name;
    ClapTrap::m_Name = Name + "_clap_name";
    FragTrap::m_hitPoints = 100;
    ScavTrap::m_energyPoints = 50;
    FragTrap::m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    std::cout << "(DiamondTrap) Copy constructor called" << std::endl;
    m_Name = copy.m_Name;
    ClapTrap::m_Name = copy.ClapTrap::m_Name;
    FragTrap::m_hitPoints = copy.FragTrap::m_hitPoints;
    ScavTrap::m_energyPoints = copy.ScavTrap::m_energyPoints;
    FragTrap::m_attackDamage = copy.FragTrap::m_attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    std::cout << "(DiamondTrap) Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_Name = src.m_Name;
        ClapTrap::m_Name = src.ClapTrap::m_Name;
        FragTrap::m_hitPoints = src.FragTrap::m_hitPoints;
        ScavTrap::m_energyPoints = src.ScavTrap::m_energyPoints;
        FragTrap::m_attackDamage = src.FragTrap::m_attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "(DiamondTrap) Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << m_Name << std:: endl;
    std::cout << " and my ClapTrap name is " << ClapTrap::m_Name << std::endl;
}