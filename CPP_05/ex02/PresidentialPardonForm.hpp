#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
public :
    PresidentialPardonForm(std::string const target);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

    void execute(Bureaucrat const &executor) const;
};

#endif