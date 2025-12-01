#include <iostream>
#include <string>
#include <exception>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request Form", target, 72, 45)
{
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy)
{
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);   
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    std::cout << "making weird drilling noises..." << std::endl;
    srand(time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized." << std::endl;
    else
        std::cout << getTarget() << " failed to robotomized." << std::endl;
}