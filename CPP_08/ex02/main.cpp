#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <list>
#include "MutantStack.tpp"

int main()
{
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

    std::cout << "=== Test 1 : main du sujet ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << "top = " << mstack.top() << std::endl; // 17
        mstack.pop();
        std::cout << "size = " << mstack.size() << std::endl; // 1

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        std::cout << "Iterating MutantStack<int>:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        // Test compatibilité avec std::stack
        std::stack<int> s(mstack); // copie la partie std::stack
        std::cout << "std::stack<int> s.top() after copy = " << s.top() << std::endl;
    }

    std::cout << "\n=== Test 2 : copy constructor ===" << std::endl;
    {
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        MutantStack<int> copy(original); // copy ctor

        std::cout << "Original: ";
        for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Copy:     ";
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        // Modif de original, copy ne doit pas changer
        original.pop();
        original.push(42);

        std::cout << "Original (after modification): ";
        for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "Copy (should be unchanged):     ";
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 3 : operator= ===" << std::endl;
    {
        MutantStack<int> a;
        a.push(10);
        a.push(20);
        a.push(30);

        MutantStack<int> b;
        b.push(99);

        b = a; // operator=

        std::cout << "a: ";
        for (MutantStack<int>::iterator it = a.begin(); it != a.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "b (after b = a): ";
        for (MutantStack<int>::iterator it = b.begin(); it != b.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 4 : MutantStack<std::string> ===" << std::endl;
    {
        MutantStack<std::string> ms;
        ms.push("hello");
        ms.push("mutant");
        ms.push("stack");

        for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end(); ++it)
            std::cout << *it << std::endl;
    }

    std::cout << "\n=== Test 5 : iteration on empty stack ===" << std::endl;
    {
        MutantStack<int> empty;

        if (empty.begin() == empty.end())
            std::cout << "Empty stack: begin() == end(), nothing to iterate." << std::endl;
        else
            std::cout << "Error: begin() != end() on empty stack" << std::endl;
    }

    std::cout << "\n=== Test 6 : Comparaison avec std::list<int> ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::list<int> l;
        l.push_back(5);
        l.push_back(17);
        l.push_back(3);
        l.push_back(5);
        l.push_back(737);
        l.push_back(0);

        std::cout << "MutantStack:" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << std::endl;

        std::cout << "std::list:" << std::endl;
        for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
            std::cout << *it << std::endl;
    }
return 0;
}