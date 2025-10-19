#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

# define TEXT "        _-_\n     /~~   ~~\\\n  /~~         ~~\\\n {               }\n  \\  _-     -_  /\n    ~  \\\\ //  ~\n _- -   | | _- _\n   _ -  | |   -_\n       // \\\\"

class   ShrubberyCreationForm : public AForm
{
public :
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm(void);

    void execute(Bureaucrat const &executor) const;
};

#endif