#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : m_type("WrongAnimal")
{
    std::cout << "WrongAnimal Default construcor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : m_type(copy.m_type)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (m_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "ANIMALLLLLLLLL" << std::endl;
}