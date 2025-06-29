#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    std::cout << "Cat Default construcor called" << std::endl;
    m_type = "Cat";
    m_brain = new Brain();
    if (m_brain == NULL)
		std::cout << "Cat Brain allocation failed" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    m_type = copy.m_type;
    m_brain = new Brain();
    if (m_brain == NULL)
		std::cout << "Cat Brain allocation failed" << std::endl;
    *m_brain = *copy.m_brain;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
        m_brain = new Brain();
        if (m_brain == NULL)
            std::cout << "Cat Brain allocation failed" << std::endl;
        *m_brain = *src.m_brain;
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

void	Cat::setIdea(size_t i, std::string idea)
{
	m_brain->setIdea(i, idea);
}

void	Cat::getIdeas(void)
{
    int i(0);
    while (i < 3)
    {
        std::cout << "Idea " << i << " is : " << m_brain->getIdea(i) << std::endl;
        i++;
    }
}