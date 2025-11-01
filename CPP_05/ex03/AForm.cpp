&#include "AForm.hpp"

AForm::AForm(void) : m_name("Default form"), m_signed(false), m_grade_sign(150), m_grade_exe(150)
{
    return ;
}

AForm::AForm(std::string n, unsigned int gs, unsigned int ge) : m_name(n), m_signed(false), m_grade_sign(gs), m_grade_exe(ge)
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

void    AForm::setTarget(std::string t)
{
    m_target = t;
}

std::string    AForm::getName(void) const
{
    return (m_name);
}

std::string    AForm::getTarget(void) const
{
    return (m_target);
}

bool    AForm::getSigned(void) const
{
    return (m_signed);
}

unsigned int    AForm::getGradeSign(void)
{
    return (m_grade_sign);
}

unsigned int    AForm::getGradeExec(void) const
{
    return (m_grade_exe);
}

void    AForm::beSigned(Bureaucrat &b)
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
    return ("AForm grade too high!\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade too low! or Bureaucrat grade too low to sign AForm!\n");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("AForm is not signed!\n");
}

std::ostream &operator<<(std::ostream &os, AForm &f)
{
    std::string s = f.getSigned() ? "signed" : "not signed";
    os << f.getName() << ", AForm (" << s << ") grade " << f.getGradeSign() << " (sign), and " << f.getGradeExec() << " (exec)." << std::endl;
    return os;
}