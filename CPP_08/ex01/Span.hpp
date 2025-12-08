#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

class Span
{
public :
    Span(unsigned int N);
    Span(Span const &copy);
    Span &operator=(Span const &src);
    ~Span(void);

    void addNumber(int nb);
    void addNumbers(std::vector<int>::iterator a, std::vector<int>::iterator b);
    int shortestSpan(void) const;
    int longestSpan(void) const;

    class SpanIsFullException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class NotEnoughNumberInSpanException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class NotEnoughSpaceInSpanException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    std::vector<int> m_vect;
    unsigned int m_N;

    Span(void);
};

#endif