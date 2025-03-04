#include "Animal.hpp"

Animal::Animal(void) : m_type("Animal")
{
    std::cout << "Animal Default construcor called" << std::endl;
}

Animal::Animal(const Animal& copy) : m_type(copy.m_type)
{
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
    }
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (m_type);
}

void    Animal::makeSound(void) const
{
    std::cout << "ANIMALLLLLLLLL" << std::endl;
}