#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    std::cout << "Cat Default construcor called" << std::endl;
    m_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    m_type = copy.m_type;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "MIAOU MIAOU" << std::endl;
}