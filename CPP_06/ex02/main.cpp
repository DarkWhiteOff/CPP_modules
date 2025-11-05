#include <iostream>
#include <string>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base* generate(void)
{
    int r = std::rand() % 3;
    if (r == 0)
        return (new A());
    else if (r == 1)
        return (new B());
    else if (r == 2)
        return (new C());
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// void identify(Base& p)
// {

// }

int main(void)
{
    Base* p = generate();

    std::cout << "identify(Base*): ";
    identify(p);

    // std::cout << "identify(Base&): ";
    // identify(*p);
}