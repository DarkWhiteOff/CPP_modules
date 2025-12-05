#include <iostream>
#include <string>
#include "iter.hpp"

// Fonction qui modifie (non-const ref)
void increment(int &x)
{
    x++;
}

// Fonction qui modifie (non-const ref) en template
template<typename T>
void increment(T &x)
{
    x++;
}

// Fonction template qui affiche (const ref)
template<typename T>
void print(T const &x)
{
    std::cout << x << " ";
}

int main(void)
{
    std::cout << "=== int array ===" << std::endl;
    int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t const len0 = 10;

    std::cout << "Before increment: ";
    ::iter(tab, len0, print);
    std::cout << std::endl;

    iter(tab, len0, increment);

    std::cout << "After increment : ";
    ::iter(tab, len0, print);
    std::cout << std::endl << std::endl;
    
    //

    std::cout << "=== double array ===" << std::endl;
    double dblTab[] = {3.14, 2.71, 1.61, 0.5772};
    size_t const len3 = 4;

    std::cout << "Before increment: ";
    ::iter(dblTab, len3, print);
    std::cout << std::endl;

    iter(dblTab, len3, increment);

    std::cout << "After increment : ";
    ::iter(dblTab, len3, print);
    std::cout << std::endl << std::endl;

    //

    std::cout << "=== string array ===" << std::endl;
    std::string strTab[] = {"Hello", "42", "World", "!"};
    size_t const len2 = 4;
    std::cout << "Strings: ";
    ::iter(strTab, len2, print);
    std::cout << std::endl << std::endl;

    //

    std::cout << "=== const int array ===" << std::endl;
    const int constTab[] = {10, 20, 30, 40};
    size_t const len4 = 4;

    std::cout << "Const ints: ";
    ::iter(constTab, len4, print);
    std::cout << std::endl;
}