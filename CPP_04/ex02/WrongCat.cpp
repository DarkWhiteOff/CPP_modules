#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "WrongCat Default construcor called" << std::endl;
    m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    m_type = copy.m_type;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
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