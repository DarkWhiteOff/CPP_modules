#include "Bureaucrat.hpp"

int main() {
  // Wrong grade at init
  try {
    Bureaucrat Z("Z", 151);
  } catch (std::exception &out) {
    std::cout << out.what() << std::endl;
  }
  std::cout << std::endl << std::endl;

  // Good grade at init + wrong decr
  try {
    Bureaucrat I("I", 150);
    I.decr();
  } catch (std::exception &out) {
    std::cout << out.what() << std::endl;
  }
  std::cout << std::endl << std::endl;

  // Good grade at init + wrong incr
  try {
    Bureaucrat G("G", 1);
    G.decr();
    G.incr();
    G.incr();
  } catch (std::exception &out) {
    std::cout << out.what() << std::endl;
  }
  std::cout << std::endl << std::endl;

  // No error
  try {
    Bureaucrat Y("Y", 1);
    std::cout << Y << std::endl;
    Y.decr();
    std::cout << Y << std::endl;
    Y.decr();
    std::cout << Y << std::endl;
    Y.incr();
    std::cout << Y << std::endl;

    Bureaucrat A(Y);
    std::cout << "I am a copy of Y: " << A << std::endl;
  } catch (std::exception &out) {
    std::cout << out.what() << std::endl;
  }
}