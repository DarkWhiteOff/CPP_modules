#include <iostream>
#include <string>
#include <exception>
#include "Array.tpp"

template<typename T>
void printArray(Array<T> &arr, const std::string &name)
{
    std::cout << name << " (size = " << arr.getSize() << "): ";
    for (unsigned int i = 0; i < arr.getSize(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== Empty array ===" << std::endl;
    Array<int> empty;
    std::cout << "empty.getSize() = " << empty.getSize() << std::endl;
    try
    {
        std::cout << "Trying empty[0]..." << std::endl;
        empty[0] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "\n=== Array of ints ===" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.getSize(); i++)
        a[i] = i * 10;
    printArray(a, "a");


    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> b(a);
    printArray(b, "b (copy of a)");
    std::cout << "Modifying b[0] = 999;" << std::endl;
    b[0] = 999;
    printArray(a, "a (unchanged)");
    printArray(b, "b (modified)");


    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> c;
    c = a;
    printArray(c, "c (assigned from a)");
    std::cout << "Modifying c[1] = 777;" << std::endl;
    c[1] = 777;
    printArray(a, "a (still unchanged)");
    printArray(c, "c (modified)");


    std::cout << "\n=== Out of bounds access ===" << std::endl;
    try
    {
        std::cout << "Trying a[5]..." << std::endl;
        a[5] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "Trying a[999]..." << std::endl;
        a[999] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "\n=== Array of std::string ===" << std::endl;
    Array<std::string> s(3);
    s[0] = "Hello";
    s[1] = "Array";
    s[2] = "Template";
    printArray(s, "s");

    std::cout << "\n=== const array ===" << std::endl;
    const Array<int> ca(5);
    // ca[0] = 100; // error
    try
    {
        std::cout << "Reading ca[0] = " << ca[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}