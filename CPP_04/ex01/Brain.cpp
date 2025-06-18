#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Default construcor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
    // int i(0);
    // while (i < 100)
	// {
	// 	if (copy.m_ideas[i].length() > 0)
    //         m_ideas[i] = copy.m_ideas[i];
	// 	i++;
	// }
	*this = copy;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        int i(0);
        while (i < 100)
		{
			if (src.m_ideas[i].length() > 0)
            	m_ideas[i] = src.m_ideas[i];
			i++;
		}
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		m_ideas[i] = idea;
	else
		std::cout << "i out of range." << std::endl;
}
std::string	Brain::getIdea(size_t i)
{
	if (i < 100)
		return(m_ideas[i]);
	else
		return ("i out of range.");
}