#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <>
#include <algorithm>
#include <sstream>

class RPN
{
public :
    RPN(void);
    RPN(std::string calc);
    RPN(const RPN &copy);
    RPN &operator=(const RPN &src);
    ~RPN(void);

    void calc();

    class FileFailedException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class BadInputException : public std::exception
    {
        private :
            std::string m_msg;
        public :
            BadInputException(std::string date);
            virtual const char *what(void) const throw();
    };

private :
    std::stack
};

#endif