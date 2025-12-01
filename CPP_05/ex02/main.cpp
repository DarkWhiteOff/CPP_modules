#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat ceo("ceo", 1);
    Bureaucrat worker1("worker1", 50);
    Bureaucrat worker2("worker2", 150);
    
    ShrubberyCreationForm s("Home");
    RobotomyRequestForm r("AI");
    PresidentialPardonForm p("White House");
    std::cout << s << r << p << std::endl;
    std::cout << ceo << worker1 << worker2 << std::endl;

    std::cout << std::endl;
    std::cout << "-- trying to sign/execute ShrubberyCreationForm --" << std::endl << std::endl;

    ceo.signForm(s);
    worker1.signForm(s);
    worker2.signForm(s);
    std::cout << std::endl;
    ceo.executeForm(s);
    worker1.executeForm(s);
    worker2.executeForm(s);

    std::cout << std::endl;
    std::cout << "-- trying to sign/execute RobotomyRequestForm --" << std::endl << std::endl;

    ceo.signForm(r);
    worker1.signForm(r);
    worker2.signForm(r);
    std::cout << std::endl;
    ceo.executeForm(r);
    worker1.executeForm(r);
    worker2.executeForm(r);

    std::cout << std::endl;
    std::cout << "-- trying to sign/execute PresidentialPardonForm --" << std::endl << std::endl;

    ceo.signForm(p);
    worker1.signForm(p);
    worker2.signForm(p);
    std::cout << std::endl;
    ceo.executeForm(p);
    worker1.executeForm(p);
    worker2.executeForm(p);

    return (0);
}