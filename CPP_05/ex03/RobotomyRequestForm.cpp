#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default Robotomy Request Form", 72, 45)
{
    setTarget("Default RRF target");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
    setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    std::cout << "making weird drilling noises..." << std::endl;
    if (rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized." << std::endl;
    else
        std::cout << getTarget() << " failed to robotomized." << std::endl;
}