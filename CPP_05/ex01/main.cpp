#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
  // Wrong grade at init
  try
  {
    Form F("F", 151, 150);
  }
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }
  try
  {
    Form F("F", 150, 151);
  }
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }
  try
  {
    Form F("F", 0, 150);
  }
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }
  
  // Sign error
    Bureaucrat  Z("Z", 76);
    Form        O("O", 75, 100);
    Z.signForm(O);

  // No error
  try
  {
    Bureaucrat  I("I", 1);
    Form        R("R", 75, 100);
    I.signForm(R);
  }
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }

    // Already signed error
    Bureaucrat  K("K", 1);
    Form        L("L", 75, 100);
    K.signForm(L);
    K.signForm(L);
  return (0);
}