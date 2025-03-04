#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    m_type = "WrongCat";
    std::cout << "WrongCat Default construcor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal()
{
    m_type = copy.m_type;
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
    }
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "MIAOU MIAOU" << std::endl;
}