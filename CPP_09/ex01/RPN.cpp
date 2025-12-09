#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include "RPN.hpp"

RPN::RPN(void)
{
    return ;
}

RPN::RPN(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-'
            && str[i] != '/' && str[i] != '*' && str[i] != ' ')
            throw BadInputException();
    }
    for(int i = 0; str[i]; i++)
    {
        if (str[i] != ' ' && isdigit(str[i]))
        {
            if (isdigit(str[i + 1]))
                throw ValueTooLargeException();
        }
    }
    m_str = str;
}

RPN::RPN(RPN const &copy)
{
    *this = copy;
}

RPN &RPN::operator=(RPN const &src)
{
    if (this != &src)
    {
        m_stack = src.m_stack;
    }
    return (*this);
}

RPN::~RPN(void)
{
    return ;
}

void RPN::calc()
{
    for(int i = 0; m_str[i]; i++)
    {
        if (isdigit(m_str[i]))
            m_stack.push(std::atoi(std::string(1, m_str[i]).c_str()));
        if (m_str[i] == '+' || m_str[i] == '-'
            || m_str[i] == '/' || m_str[i] == '*')
            {
                int res(0);
                int a(m_stack.top());
                m_stack.pop();
                int b(m_stack.top());
                m_stack.pop();
                if (m_str[i] == '+')
                    res = b + a;
                if (m_str[i] == '-')
                    res = b - a;
                if (m_str[i] == '/')
                    res = b / a;
                if (m_str[i] == '*')
                    res = b * a;
                m_stack.push(res);
            }
    }
    std::cout << m_stack.top() << std::endl;
}

const char *RPN::ValueTooLargeException::what(void) const throw()
{
    return ("Error: Value is too large.");
}

const char *RPN::BadInputException::what(void) const throw()
{
    return ("Error");
}