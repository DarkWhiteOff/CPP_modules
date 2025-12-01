#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
public :
    PresidentialPardonForm(std::string const target);
    ~PresidentialPardonForm(void);

    void execute(Bureaucrat const &executor) const;
};

#endif