#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog Default construcor called" << std::endl;
    m_type = "Dog";
    m_brain = new Brain();
    if (m_brain == NULL)
	{
		perror("Dpg Brain allocation failed");
		exit(1);
	}
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    m_type = copy.m_type;
    m_brain = new Brain();
    *m_brain = *copy.m_brain;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
        m_brain = new Brain();
        *m_brain = *src.m_brain;
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

// Getter
void	Dog::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
		std::cout << "\tIdea " << i << " of the Dog is: \"" << m_brain->getIdea(i) << "\" at the address " << m_brain->getIdeaAddress(i) << std::endl;
}

// Setter
void	Dog::setIdea(size_t i, std::string idea)
{
		m_brain->setIdea(i, idea);
}