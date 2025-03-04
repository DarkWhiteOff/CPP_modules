#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    m_type = "Cat";
    std::cout << "Cat Default construcor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal()
{
    m_type = copy.m_type;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
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