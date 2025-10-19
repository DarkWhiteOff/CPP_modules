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
  try
  {
    Bureaucrat  Z("Z", 76);
    Form        O("O", 75, 100);
    Z.signForm(O);
  }
  catch(std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }

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
}