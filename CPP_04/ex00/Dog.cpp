#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    m_type = "Dog";
    std::cout << "Dog Default construcor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal()
{
    m_type = copy.m_type;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "WAF WAF" << std::endl;
}