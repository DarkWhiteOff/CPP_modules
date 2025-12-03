#include <iostream>
#include <string>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(nullptr));
    int r = std::rand() % 3;
    if (r == 0)
        return (new A());
    else if (r == 1)
        return (new B());
    else if (r == 2)
        return (new C());
    else
        std::cout << "Error generating a Base class" << std::endl;
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A (pointer)" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B (pointer)" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C (pointer)" << std::endl;
    else
        std::cout << "Couldn't identified type (pointer)" << std::endl;
}

void identify(Base& p)
{
    try {
        A& aref = dynamic_cast<A&>(p);
        std::cout << "A (reference)" << std::endl;
        return ;
    }
    catch (std::exception &o) {
    }
    try {
        B& aref = dynamic_cast<B&>(p);
        std::cout << "B (reference)" << std::endl;
        return ;
    }
    catch (std::exception &o) {
    }
    try {
        C& aref = dynamic_cast<C&>(p);
        std::cout << "C (reference)" << std::endl;
        return ;
    }
    catch (std::exception &o) {
        std::cout << "Couldn't identified type (reference)" << std::endl;
    }
}

class D : public Base {

};

int main(void)
{
    // Good class
    Base* p = generate();
    std::cout << "identify(Base*): ";
    identify(p);
    std::cout << "identify(Base&): ";
    identify(*p);

    // Wrong class
    Base* p1 = new D;
    std::cout << "identify(Base*): ";
    identify(p1);
    std::cout << "identify(Base&): ";
    identify(*p1);

    Base* p2;
    std::cout << "identify(Base*): ";
    identify(p2);
    std::cout << "identify(Base&): ";
    identify(*p2);
    return (0);
}