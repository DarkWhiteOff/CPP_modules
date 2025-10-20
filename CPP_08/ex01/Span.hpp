#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

class Span
{
public :
    Span(void);
    Span(unsigned int N);
    Span(const Span &copy);
    Span &operator=(const Span &src);
    ~Span(void);

    void    addNumber(int nb);
    void    addNumbers(std::vector<int>::iterator a, std::vector<int>::iterator b);
    int shortestSpan(void);
    int longestSpan(void);

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
};

#endif