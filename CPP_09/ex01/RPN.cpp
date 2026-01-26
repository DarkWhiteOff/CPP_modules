#include "RPN.hpp"
#include <iostream>
#include <cctype>

RPN::RPN(void) : m_str("")
{
    return ;
}

RPN::RPN(std::string const str) : m_str(str)
{
    return ;
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

const char *RPN::BadInputException::what(void) const throw()
{
    return ("Error");
}

void RPN::validateRPN()
{
    if (m_str.empty())
        throw BadInputException();
    for(size_t i = 0; i < m_str.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(m_str[i])) && m_str[i] != '+'
            && m_str[i] != '-' && m_str[i] != '/' && m_str[i] != '*' && m_str[i] != ' ')
            throw BadInputException();
    }
    bool sum = false;
    for(size_t i = 0; i < m_str.size(); i++)
    {
        if (m_str[i] != ' ')
        {
            if (i + 1 < m_str.size() && m_str[i + 1] != ' ')
                throw BadInputException();
            sum = true;
        }
    }
    if (!sum)
        throw BadInputException();
}

void RPN::calcRPN()
{
    validateRPN();
    while (!m_stack.empty())
        m_stack.pop();
    for(size_t i = 0; i < m_str.size(); i++)
    {
        char c = m_str[i];
        if (std::isdigit(static_cast<unsigned char>(c)))
            m_stack.push(c - '0');
        else if (c == '+' || c == '-'
            || c == '/' || c == '*')
            {
                if (m_stack.size() < 2)
                    throw BadInputException();
                int a = m_stack.top();
                m_stack.pop();
                int b = m_stack.top();
                m_stack.pop();
            
                int res = 0;
                if (c == '+')
                    res = b + a;
                else if (c == '-')
                    res = b - a;
                else if (c == '*')
                    res = b * a;
                else
                {
                    if (a == 0)
                        throw BadInputException();
                    res = b / a;
                }
                m_stack.push(res);
            }
    }
    if (m_stack.size() != 1)
        throw BadInputException();
    std::cout << m_stack.top() << std::endl;
}