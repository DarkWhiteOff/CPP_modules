#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <stack>
#include "RPN.hpp"

RPN::RPN(void) : m_str("")
{
    return ;
}

RPN::RPN(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '+' && str[i] != '-'
            && str[i] != '/' && str[i] != '*' && str[i] != ' ')
            throw BadInputException();
    }
    for(int i = 0; str[i]; i++)
    {
        if (str[i] != ' ' && std::isdigit(str[i]))
        {
            if (std::isdigit(str[i + 1]))
                throw BadInputException();
        }
    }
    m_str = str;
}

RPN::RPN(RPN const &copy)
{
    (*this) = copy;
}

RPN &RPN::operator=(RPN const &src)
{
    if (this != &src)
    {
        m_str = src.m_str;
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
        if (std::isdigit(m_str[i]))
            m_stack.push(std::atoi(std::string(1, m_str[i]).c_str()));
        if (m_str[i] == '+' || m_str[i] == '-'
            || m_str[i] == '/' || m_str[i] == '*')
            {
                if (m_stack.size() < 2)
                    throw BadInputException();
                int res(0);
                int a(m_stack.top());
                m_stack.pop();
                int b(m_stack.top());
                m_stack.pop();
                if (m_str[i] == '/' && a == 0)
                    throw BadInputException();
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
    if (m_stack.size() != 1)
        throw BadInputException();
    std::cout << m_stack.top() << std::endl;
}

const char *RPN::BadInputException::what(void) const throw()
{
    return ("Error");
}