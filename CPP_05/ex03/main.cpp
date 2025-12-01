#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
  Intern sl;

  // Error
  AForm *form_name_wrong;
  AForm *form_name_wrong1;
  try {
      form_name_wrong = sl.makeForm("presidential p", "white house");
  }
  catch(std::exception &o) {
      std::cout << o.what() << std::endl;
  }
  try {
      form_name_wrong1 = sl.makeForm("Presidential pardon", "white house"); 
  }
  catch(std::exception &o) {
      std::cout << o.what() << std::endl;
  }
  (void)form_name_wrong;
  (void)form_name_wrong1;

  // Working
  AForm *form1;
  AForm *form2;
  AForm *form3;

  try {
      form1 = sl.makeForm("presidential pardon", "white house");
  }
  catch(std::exception &o) {
      std::cout << o.what() << std::endl;
  }
  try {
      form2 = sl.makeForm("robotomy request", "AI");
  }
  catch(std::exception &o) {
      std::cout << o.what() << std::endl;
  }
  try {
      form3 = sl.makeForm("shrubbery creation", "home");
  }
  catch(std::exception &o) {
      std::cout << o.what() << std::endl;
  }
  std::cout << *form1 << *form2 << *form3 << std::endl;
  (void)form2;

  Bureaucrat boss("boss", 1);
  Bureaucrat worker1("worker1", 149);
  std::cout << boss << worker1 << std::endl;

  boss.signForm(*form1);
  boss.executeForm(*form1);

  worker1.signForm(*form3);
  worker1.executeForm(*form3);

  delete form1;
  delete form2;
  delete form3;

  return (0);
}