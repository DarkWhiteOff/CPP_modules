#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
    return ;
}

Bureaucrat::Bureaucrat(std::string n, unsigned int g) : m_name(n), m_grade(g)
{
    if (m_grade < 1)
        throw GradeTooHighException();
    if (m_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

std::string    Bureaucrat::getName(void)
{
    return (m_name);
}

unsigned int    Bureaucrat::getGrade(void)
{
    return (m_grade);
}

void	Bureaucrat::incr()
{
    m_grade--;
    if (m_grade < 1)
        throw GradeTooHighException();

}

void	Bureaucrat::decr()
{
    m_grade++;
    if (m_grade > 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!\n");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bc)
{
  os << bc.getName() << ", bureaucrat grade " << bc.getGrade() << "." << std::endl;
  return os;
}