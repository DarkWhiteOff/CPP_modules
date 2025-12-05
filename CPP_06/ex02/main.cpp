#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3;
    if (r == 0)
        return (new A);
    else if (r == 1)
        return (new B);
    else if (r == 2)
        return (new C);
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
        (void)aref;
        std::cout << "A (reference)" << std::endl;
        return ;
    }
    catch (std::exception &o) {
    }
    try {
        B& bref = dynamic_cast<B&>(p);
        (void)bref;
        std::cout << "B (reference)" << std::endl;
        return ;
    }
    catch (std::exception &o) {
    }
    try {
        C& cref = dynamic_cast<C&>(p);
        (void)cref;
        std::cout << "C (reference)" << std::endl;
        return ;
    }
    catch (std::exception &o) {
        std::cout << "Couldn't identified type (reference)" << std::endl;
    }
}

int main(void)
{
    std::cout << "=== generate() ===" << std::endl;
    Base* p = generate();
    std::cout << "identify(Base*): ";
    identify(p);
    std::cout << "identify(Base&): ";
    identify(*p);
    delete p;

    std::cout << "\n=== Manual A/B/C ===" << std::endl;

    Base* pa = new A;
    Base* pb = new B;
    Base* pc = new C;
    std::cout << "A via pointer: ";
    identify(pa);
    std::cout << "A via ref: ";
    identify(*pa);
    std::cout << "B via pointer: ";
    identify(pb);
    std::cout << "B via ref: ";
    identify(*pb);
    std::cout << "C via pointer: ";
    identify(pc);
    std::cout << "C via ref: ";
    identify(*pc);
    delete pa;
    delete pb;
    delete pc;

    std::cout << "\n=== NULL ptr test ===" << std::endl;
    Base* pn = NULL;
    std::cout << "NULL via pointer: ";
    identify(pn);
    return (0);
}