#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default Shrubbery Creation Form", 145, 137)
{
    setTarget("Default SCF target");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
    setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream tfile(filename);
    tfile << TEXT << std::endl;
    tfile.close();
}