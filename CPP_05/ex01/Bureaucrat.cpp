#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : m_name("Default Bureaucrat"), m_grade(150)
{
    return ;
}

Bureaucrat::Bureaucrat(std::string const n, unsigned int g) : m_name(n), m_grade(g)
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

std::string const Bureaucrat::getName(void) const
{
    return (m_name);
}

unsigned int Bureaucrat::getGrade(void) const
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

void    Bureaucrat::signForm(Form &f)
{
    try {
        f.beSigned(*this);
        std::cout << m_name << " signed " << f.getName() << std::endl;
    }
    catch(std::exception &o) {
        std::cout << m_name << " couldn't sign " << f.getName() << " because " << o.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj)
{
    output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return (output);
}