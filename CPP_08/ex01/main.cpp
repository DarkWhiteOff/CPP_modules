#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main( void )
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    std::cout << "\n=== Exception : Not enough numbers in span ===" << std::endl;
    {
        Span sp(5);
        try {
            sp.shortestSpan();
        } catch (std::exception &e) {
            std::cout << "shortestSpan() : " << e.what() << std::endl;
        }
        try {
            sp.addNumber(42);
            sp.longestSpan();
        } catch (std::exception &e) {
            std::cout << "longestSpan() : " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Exception : Full span ===" << std::endl;
    {
        Span sp(3);
        try {
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
        } catch (std::exception &e) {
            std::cout << "addNumber : " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Test addNumbers(range) ===" << std::endl;
    {
        Span sp(10);
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);

        try {
            sp.addNumbers(v.begin(), v.end());
            std::cout << "Range added. Shortest = " << sp.shortestSpan()
                      << ", Longest = " << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "addNumbers : " << e.what() << std::endl;
        }

        std::cout << "Test overflow de addNumbers..." << std::endl;
        std::vector<int> big(10, 100);
        try {
            sp.addNumbers(big.begin(), big.end());
        } catch (std::exception &e) {
            std::cout << "addNumbers overflow : " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== 10000 numbers ===" << std::endl;
    {
        Span sp(10000);
        std::vector<int> v;
        v.reserve(10000);
        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; ++i)
            v.push_back(std::rand());
        try {
            sp.addNumbers(v.begin(), v.end());
            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception : " << e.what();
        }
    }

    std::cout << "\n=== Doubles ===" << std::endl;
    {
        Span sp(4);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(20);
        std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
    }

    return 0;
}