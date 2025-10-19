#include "Form.hpp"

Form::Form(void) : m_name("Default form"), m_signed(false), m_grade_sign(150), m_grade_exe(150)
{
    return ;
}

Form::Form(std::string n, unsigned int gs, unsigned int ge) : m_name(n), m_signed(false), m_grade_sign(gs), m_grade_exe(ge)
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

std::string    Form::getName(void)
{
    return (m_name);
}

bool    Form::getSigned(void)
{
    return (m_signed);
}

unsigned int    Form::getGradeSign(void)
{
    return (m_grade_sign);
}

unsigned int    Form::getGradeExec(void)
{
    return (m_grade_exe);
}

void    Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= m_grade_sign)
        m_signed = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high!\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low! or Bureaucrat grade too low to sign form!\n");
}

std::ostream &operator<<(std::ostream &os, Form &f)
{
    std::string s = f.getSigned() ? "signed" : "not signed";
    os << f.getName() << ", form (" << s << ") grade " << f.getGradeSign() << " (sign), and " << f.getGradeExec() << " (exec)." << std::endl;
    return os;
}