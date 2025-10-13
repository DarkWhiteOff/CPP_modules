#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
    return ;
}

Bureaucrat::Bureaucrat(std::string n) : m_name(n)
{
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        m_name = src.m_name;
        m_grade = src.m_grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << m_name << " destroyed" << std::endl;
}

void    Bureaucrat::getName(void)
{
    std::cout << m_name << std::endl;
}

void    Bureaucrat::getGrade(void)
{
    std::cout << m_grade << std::endl;
}

// POST INCREMENT/DECREMENT
Bureaucrat	Bureaucrat::operator++(int)
{
    Bureaucrat tmp = *this;
    --m_grade;
    return (tmp);
}

Bureaucrat	Bureaucrat::operator--(int)
{
    Bureaucrat tmp = *this;
    ++m_grade;
    return (tmp);
}