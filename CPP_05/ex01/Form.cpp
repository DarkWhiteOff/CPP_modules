#include "Form.hpp"

Form::Form(void)
{
    std::cout << m_name << " created" << std::endl;
    return ;
}

Form::Form(std::string n, unsigned int g) : m_name(n), m_grade(g)
{
    std::cout << m_name << " created" << std::endl;
    if (m_grade < 1)
        throw GradeTooLowException();
    if (m_grade > 150)
        throw GradeTooHighException();
    return ;
}

Form::Form(const Bureaucrat &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Form &Form::operator=(const Bureaucrat &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        // m_name = src.m_name;
        m_grade = src.m_grade;
    }
    return (*this);
}

Form::~Form(void)
{
    std::cout << m_name << " destroyed" << std::endl;
}

std::string    Form::getName(void)
{
    return (m_name);
}

unsigned int    Form::getGrade(void)
{
    return (m_grade);
}

// POST INCREMENT/DECREMENT
void	Form::incr()
{
    --m_grade;
    if (m_grade < 1)
    {
        m_grade++;
        throw GradeTooLowException();
    }

}

void	Form::decr()
{
    ++m_grade;
    if (m_grade > 150)
    {
        m_grade--;
        throw GradeTooHighException();
    }
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!\n");
}

std::ostream &operator<<(std::ostream &os, Form &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."
     << std::endl;
  return os;
}