#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include "easyfind.hpp"

int main()
{
    std::cout << "=== std::vector<int> found ===" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 10; ++i)
            v.push_back(i * 2); // 0, 2, 4, 6
        try
        {
            easyfind(v, 8);
            std::cout << "easyfind(v, 8): found" << std::endl;
        }
        catch (const NoOccurenceFound &e)
        {
            std::cout << "easyfind(v, 8): " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== std::vector<int> not found ===" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 10; ++i)
            v.push_back(i * 3); // 0, 3, 6, 9
        try
        {
            easyfind(v, 5);
            std::cout << "easyfind(v, 5): found" << std::endl;
        }
        catch (const NoOccurenceFound &e)
        {
            std::cout << "easyfind(v, 5): " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== std::list<int> found ===" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(42);
        lst.push_back(7);
        lst.push_back(1337);
        lst.push_back(42);
        try
        {
            easyfind(lst, 42);
            std::cout << "easyfind(lst, 42): found" << std::endl;
        }
        catch (const NoOccurenceFound &e)
        {
            std::cout << "easyfind(lst, 42): " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== std::list<int> not found ===" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        try
        {
            easyfind(lst, 10);
            std::cout << "easyfind(lst, 10): found" << std::endl;
        }
        catch (const NoOccurenceFound &e)
        {
            std::cout << "easyfind(lst, 10): " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== empty container ===" << std::endl;
    {
        std::vector<int> empty;
        try
        {
            easyfind(empty, 1);
            std::cout << "easyfind(empty, 1): found" << std::endl;
        }
        catch (const NoOccurenceFound &e)
        {
            std::cout << "easyfind(empty, 1): " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== multiple occurences ===" << std::endl;
    {
        std::vector<int> v;
        v.push_back(5);
        v.push_back(5);
        v.push_back(5);
        try
        {
            easyfind(v, 5);
            std::cout << "easyfind(v, 5): found" << std::endl;
        }
        catch (const NoOccurenceFound &e)
        {
            std::cout << "easyfind(v, 5): " << e.what() << std::endl;
        }
    }
    return (0);
}