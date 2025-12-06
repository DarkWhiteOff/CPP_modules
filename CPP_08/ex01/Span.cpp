#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <algorithm>
#include "Span.hpp"

Span::Span(unsigned int N) : m_N(N)
{
    return ;
}

Span::Span(const Span &copy)
{
    (*this) = copy;
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        m_vect = src.m_vect;
        m_N = src.m_N;
    }
    return (*this);
}

Span::~Span(void)
{
    return ;
}

void    Span::addNumber(int nb)
{
    if (m_vect.size() == m_N)
        throw SpanIsFullException();
    m_vect.push_back(nb);
}

void    Span::addNumbers(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
    if ((m_vect.size() + std::distance(a, b)) > m_N)
        throw NotEnoughSpaceInSpanException();
    m_vect.insert(m_vect.end(), a, b);
}

int    Span::shortestSpan(void) const
{
    if (m_vect.size() == 0 || m_vect.size() == 1)
        throw NotEnoughNumberInSpanException();
    std::vector<int> sorted_vect = m_vect;
    std::sort(sorted_vect.begin(), sorted_vect.end());
    if (std::adjacent_find(sorted_vect.begin(), sorted_vect.end()) != sorted_vect.end())
        return (0);
    size_t i(0);
    int res(sorted_vect[i + 1] - sorted_vect[i]);
    int diff(sorted_vect[i + 1] - sorted_vect[i]);
    while (i + 1 < sorted_vect.size())
    {
        diff = (sorted_vect[i + 1] - sorted_vect[i]);
        res = std::min(res, diff);
        i++;
    }
    return (res);
}

int    Span::longestSpan(void) const
{
    if (m_vect.size() == 0 || m_vect.size() == 1)
        throw NotEnoughNumberInSpanException();
    int min = *std::min_element(m_vect.begin(), m_vect.end());
    int max = *std::max_element(m_vect.begin(), m_vect.end());
    int res = max - min;
    return (res);
}

const char *Span::SpanIsFullException::what(void) const throw()
{
    return ("Span Is Full!");
}

const char *Span::NotEnoughNumberInSpanException::what(void) const throw()
{
    return ("Not Enough Number In Span!");
}

const char *Span::NotEnoughSpaceInSpanException::what(void) const throw()
{
    return ("Not Enough Space In Span!");
}