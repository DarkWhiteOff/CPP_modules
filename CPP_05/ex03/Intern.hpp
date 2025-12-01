#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class   Intern
{
public :
    Intern(void);
    ~Intern(void);

    Intern(Intern const &copy);
    Intern &operator=(Intern const &src);

    AForm    *makeForm(std::string const formName, std::string const formTarget);

    class FormNameFailedException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };
};

#endif