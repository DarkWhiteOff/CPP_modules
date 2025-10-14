#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
    std::cout << m_name << " created" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string n, unsigned int g) : m_name(n), m_grade(g)
{
    std::cout << m_name << " created" << std::endl;
    if (m_grade < 1)
        throw GradeTooLowException();
    if (m_grade > 150)
        throw GradeTooHighException();
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
        // m_name = src.m_name;
        m_grade = src.m_grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << m_name << " destroyed" << std::endl;
}

std::string    Bureaucrat::getName(void)
{
    return (m_name);
}

unsigned int    Bureaucrat::getGrade(void)
{
    return (m_grade);
}

// POST INCREMENT/DECREMENT
void	Bureaucrat::incr()
{
    --m_grade;
    if (m_grade < 1)
    {
        m_grade++;
        throw GradeTooLowException();
    }

}

void	Bureaucrat::decr()
{
    ++m_grade;
    if (m_grade > 150)
    {
        m_grade--;
        throw GradeTooHighException();
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!\n");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."
     << std::endl;
  return os;
}