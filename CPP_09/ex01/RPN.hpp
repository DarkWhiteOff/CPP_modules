#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <exception>
#include <stack>

class RPN
{
public :
    RPN(void);
    RPN(std::string const str);
    RPN(RPN const &copy);
    RPN &operator=(RPN const &src);
    ~RPN(void);

    void calcRPN();

    class BadInputException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    std::string m_str;
    std::stack<int> m_stack;

    void validateRPN();
};

#endif