#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <sstream>

class RPN
{
public :
    RPN(void);
    RPN(std::string str);
    RPN(const RPN &copy);
    RPN &operator=(const RPN &src);
    ~RPN(void);

    void calc();

    class ValueTooLargeException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class BadInputException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    std::string m_str;
    std::stack<int> m_stack;
};

#endif