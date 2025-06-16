#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog Default construcor called" << std::endl;
    m_type = "Dog";
    m_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    m_type = copy.m_type;
    m_brain = new Brain(*(copy.m_brain));
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
        delete m_brain;
        m_brain = new Brain(*(src.m_brain));
    }
    return (*this);
}

Dog::~Dog(void)
{
    delete m_brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "WAF WAF" << std::endl;
}