#include <iostream>
#include <string>
#include "Intern.hpp"

typedef struct	list
{
	std::string	name;
	AForm	*form;
}	t_list;

Intern::Intern(void)
{
    return ;
}

Intern::~Intern(void)
{
    return ;
}

AForm    *Intern::makeForm(std::string const formName, std::string const formTarget)
{
    AForm	*F = NULL;
	t_list	list[3] =
	{
		{"robotomy request", new RobotomyRequestForm(formTarget)},
		{"presidential pardon", new PresidentialPardonForm(formTarget)},
		{"shrubbery creation", new ShrubberyCreationForm(formTarget)}
	};
	for (int i = 0; i < 3; i++)
	{
		if (list[i].name == formName)
			F = list[i].form;
		else
			delete (list[i].form);
	}
	if (!F)
		throw FormNameFailedException();
    std::cout << "Intern creates " << formName << std::endl;
	return (F);
}

const char *Intern::FormNameFailedException::what() const throw()
{
    return ("Form name does not exist!\n");
}