#include "Cat.hpp"

Cat::Cat(void) : Animal(), m_brain(0)
{
    m_type = "Cat";
    m_brain = new Brain();
    std::cout << "Cat Default construcor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal()
{
    m_type = copy.m_type;
    m_brain = new Brain(*(copy.m_brain));
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
        delete m_brain;
        m_brain = new Brain(*(src.m_brain));
    }
    return (*this);
}

Cat::~Cat(void)
{
    delete m_brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "MIAOU MIAOU" << std::endl;
}