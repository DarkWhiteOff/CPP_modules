#include "RPN.hpp"

RPN::RPN(void)
{
    
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
    {
        
    }
    return (*this);
}

RPN::~RPN(void)
{
    return ;
}

const char *RPN::FileFailedException::what(void) const throw()
{
    return ("Error: could not open file.");
}

RPN::BadInputException::BadInputException(std::string date)
{
    m_msg = "Error: bad input => " + date;
}

const char *RPN::BadInputException::what(void) const throw()
{
    return (m_msg.c_str());
}