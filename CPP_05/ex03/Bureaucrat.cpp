#include <iostream>
#include <string>
#include <exception>
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

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : m_name(copy.m_name), m_grade(copy.m_grade)
{
    return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        m_grade = src.m_grade;
    }
    return (*this);
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

void    Bureaucrat::signForm(AForm &f)
{
    try {
        f.beSigned(*this);
        std::cout << m_name << " signed " << f.getName() << std::endl;
    }
    catch(std::exception &o) {
        std::cout << m_name << " couldn't sign " << f.getName() << " because " << o.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form) const
{
    try {
        form.execute(*this);
        std::cout << m_name << " executed " << form.getName() << std::endl;
    }
    catch(std::exception &o) {
        std::cout << m_name << " couldn't execute " << form.getName() << " because " << o.what() << std::endl;
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