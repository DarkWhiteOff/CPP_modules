#include <iostream>
#include <string>

int main(void)
{
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR(&str);
    std::string& stringREF(str);

    std::cout << "Memory adress of string variable : " << &str << std::endl;
    std::cout << "Memory adress held by stringPTR : " << stringPTR << std::endl;
    std::cout << "Memory adress held by stringREF : " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of string variable : " << str << std::endl;
    std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;
    return (0);
}