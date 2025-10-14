#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class   Form
{
public :
    Form(void);
    Form(std::string n, unsigned int g);
    Form(const Form &copy);
    Form &operator=(const Form &src);
    ~Form(void);
    std::string    getName(void);
    unsigned int    getGrade(void);

    void incr(void);
    void decr(void);

    class GradeTooHighException : public std::exception
    {
        public :
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public :
            const char *what() const throw();
    };

private :
    std::string const m_name;
    bool sign;
    unsigned int const m_grade;
};

std::ostream &operator<<(std::ostream &os, Form &obj);

#endif