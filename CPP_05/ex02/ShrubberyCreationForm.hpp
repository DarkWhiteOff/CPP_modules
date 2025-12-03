#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include "AForm.hpp"

# define TEXT "        _-_\n     /~~   ~~\\\n  /~~         ~~\\\n {               }\n  \\  _-     -_  /\n    ~  \\\\ //  ~\n _- -   | | _- _\n   _ -  | |   -_\n       // \\\\"

class   ShrubberyCreationForm : public AForm
{
public :
    ShrubberyCreationForm(std::string const target);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

    void execute(Bureaucrat const &executor) const;
};

#endif