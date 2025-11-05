#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : m_name("Default name"), m_grade(150)
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

unsigned int    Bureaucrat::getGrade(void) const
{
    return (m_grade);
}

void	Bureaucrat::incr(void)
{
    m_grade--;
    if (m_grade < 1)
        throw GradeTooHighException();

}

void	Bureaucrat::decr(void)
{
    m_grade++;
    if (m_grade > 150)
        throw GradeTooLowException();
}

void    Bureaucrat::signForm(AForm &f)
{
    f.beSigned(*this);
    std::cout << m_name << " signed " << f.getName();
}

void    Bureaucrat::executeForm(AForm const &form) const
{
    form.execute(*this);
    std::cout << m_name << " executed " << form.getName();
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