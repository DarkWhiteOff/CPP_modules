#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "PmergeMe.hpp"

void autoTest(const std::string& name, char **tests)
{
    std::cout << "\n===== " << name << " =====\n";
    try
    {
        PmergeMe p(tests);
        p.make();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void runAutomaticTests()
{
    std::cout << "\nAuto tests...\n";

    char* vals1[] = {"3", "5", "9", "7", "4"};
    autoTest("Test 1 : Basic set", vals1);

    char* vals2[] = {"1", "2", "3", "4", "5"};
    autoTest("Test 2 : Already sorted", vals2);

    char* vals3[] = {"9", "8", "7", "6", "5"};
    autoTest("Test 3 : Reverse sorted", vals3);

    char* vals4[] = {"5", "1", "5", "2", "5", "3"};
    autoTest("Test 4 : Duplicates", vals4);

    char* vals5[] = {"42"};
    autoTest("Test 5 : Single element", vals5);

    char* vals6[] = {"10", "3", "7"};
    autoTest("Test 6 : Odd count", vals6);
}


int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    else if (argc == 1)
    {
        runAutomaticTests();
        return (0);
    }
    try
    {
        PmergeMe p(argv);
        p.make();
    }
    catch (std::exception &o)
    {
        std::cerr << o.what() << std::endl;
    }
    return (0);
}