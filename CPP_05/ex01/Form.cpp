#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

Form::Form(void) : m_name("Default Form"), m_signed(false), m_grade_sign(150), m_grade_exe(150)
{
    return ;
}

Form::Form(std::string const n, unsigned int gs, unsigned int ge) : m_name(n), m_signed(false), m_grade_sign(gs), m_grade_exe(ge)
{
    if (m_grade_sign < 1 || m_grade_exe < 1)
        throw GradeTooHighException();
    if (m_grade_sign > 150 || m_grade_exe > 150)
        throw GradeTooLowException();
}

Form::~Form(void)
{
    return ;
}

Form::Form(Form const &copy) : m_name(copy.m_name), m_signed(copy.m_signed), m_grade_sign(copy.m_grade_sign), m_grade_exe(copy.m_grade_exe)
{
    return ;
}

Form &Form::operator=(Form const &src)
{
    if (this != &src)
    {
        m_signed = src.m_signed;
    }
    return (*this);
}

std::string const Form::getName(void) const
{
    return (m_name);
}

bool Form::getSigned(void) const
{
    return (m_signed);
}

unsigned int Form::getGradeSign(void) const
{
    return (m_grade_sign);
}

unsigned int Form::getGradeExec(void) const
{
    return (m_grade_exe);
}

void    Form::beSigned(Bureaucrat const &b)
{
    if (m_signed)
        throw AlreadySignedException();
    if (b.getGrade() <= m_grade_sign)
        m_signed = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low! (or Bureaucrat too low to sign this form)");
}

const char *Form::AlreadySignedException::what() const throw()
{
    return ("Form was already signed!");
}

std::ostream &operator<<(std::ostream &output, Form const &obj)
{
    std::string s = obj.getSigned() ? "signed" : "not signed";
    output << obj.getName() << ", form (" << s << ") grade " << obj.getGradeSign() << " (sign), and " << obj.getGradeExec() << " (exec)." << std::endl;
    return (output);
}