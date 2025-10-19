#include "Bureaucrat.hpp"

int main() {
  // Wrong grade at init
  try
  {
    Bureaucrat Z("Z", 151);
  }
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }

  // Good grade at init + wrong decr
  try
  {
    Bureaucrat I("I", 150);
    I.decr();
  } 
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }

  // Good grade at init + wrong incr
  try
  {
    Bureaucrat G("G", 1);
    G.decr();
    G.incr();
    G.incr();
  }
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }

  // No error
  try
  {
    Bureaucrat Y("Y", 1);
    std::cout << Y << std::endl;
    Y.decr();
    std::cout << Y << std::endl;
    Y.decr();
    std::cout << Y << std::endl;
    Y.incr();
    std::cout << Y << std::endl;
  }
  catch (std::exception &o)
  {
    std::cout << o.what() << std::endl;
  }
}