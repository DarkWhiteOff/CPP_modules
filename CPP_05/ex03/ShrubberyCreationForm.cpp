#include <iostream>
#include <string>
#include <exception>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Shrubbery Creation Form", target, 145, 137)
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);   
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream tfile(filename);
    if (!tfile)
        return ;
    tfile << TEXT << std::endl;
    tfile.close();
}