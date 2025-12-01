#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

AForm::AForm(void) : m_name("Default AForm"), m_target("Default target"), m_signed(false), m_grade_sign(150), m_grade_exe(150)
{
    return ;
}

AForm::AForm(std::string const n, std::string const t, unsigned int gs, unsigned int ge) : m_name(n), m_target(t), m_signed(false), m_grade_sign(gs), m_grade_exe(ge)
{
    if (m_grade_sign < 1 || m_grade_exe < 1)
        throw GradeTooHighException();
    if (m_grade_sign > 150 || m_grade_exe > 150)
        throw GradeTooLowException();
}

AForm::~AForm(void)
{
    return ;
}

std::string const AForm::getTarget(void) const
{
    return (m_target);
}

std::string const AForm::getName(void) const
{
    return (m_name);
}

bool AForm::getSigned(void) const
{
    return (m_signed);
}

unsigned int AForm::getGradeSign(void) const
{
    return (m_grade_sign);
}

unsigned int AForm::getGradeExec(void) const
{
    return (m_grade_exe);
}

void    AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() <= m_grade_sign)
        m_signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    (void)executor;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade too low! (or Bureaucrat too low to sign/execute this form)");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("AForm is not signed!");
}

std::ostream &operator<<(std::ostream &output, AForm const &obj)
{
    std::string s = obj.getSigned() ? "signed" : "not signed";
    output << obj.getName() << ", form (" << s << "), grade " << obj.getGradeSign() << " (sign), and " << obj.getGradeExec() << " (exec)." << std::endl;
    return (output);
}