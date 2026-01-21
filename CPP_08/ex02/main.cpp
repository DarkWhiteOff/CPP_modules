#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <algorithm>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== main du sujet ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n=== Comparaison avec std::list<int> ===" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.pop_back();
    std::cout << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    //[...]
    l.push_back(0);
    std::list<int>::iterator itl = l.begin();
    std::list<int>::iterator itel = l.end();
    ++itl;
    --itl;
    while (itl != itel)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }

    std::cout << "\n=== copy constructor ===" << std::endl;
    {
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        MutantStack<int> copy(original);

        std::cout << "Original: ";
        for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Copy:     ";
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        original.pop();
        original.push(42);

        std::cout << "Original : ";
        for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Copy :     ";
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    std::cout << "\n=== operator= ===" << std::endl;
    {
        MutantStack<int> a;
        a.push(10);
        a.push(20);
        a.push(30);

        MutantStack<int> b;
        b.push(99);

        b = a;

        std::cout << "a: ";
        for (MutantStack<int>::iterator it = a.begin(); it != a.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "b: ";
        for (MutantStack<int>::iterator it = b.begin(); it != b.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    std::cout << "\n=== MutantStack<std::string> ===" << std::endl;
    {
        MutantStack<std::string> ms;
        ms.push("hello");
        ms.push("mutant");
        ms.push("stack");

        for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end(); it++)
            std::cout << *it << std::endl;
    }

    std::cout << "\n=== iteration on empty stack ===" << std::endl;
    {
        MutantStack<int> empty;

        if (empty.begin() == empty.end())
            std::cout << "Empty stack: begin() == end(), nothing to iterate." << std::endl;
        else
            std::cout << "Error: begin() != end() on empty stack" << std::endl;
    }

    return 0;
}