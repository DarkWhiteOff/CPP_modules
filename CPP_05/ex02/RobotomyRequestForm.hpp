#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   RobotomyRequestForm : public AForm
{
public :
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm(void);

    void execute(Bureaucrat const &executor) const;
};

#endif