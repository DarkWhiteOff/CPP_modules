#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default Presidential Pardon Form", 25, 5)
{
    setTarget("Default PPF target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
    setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}