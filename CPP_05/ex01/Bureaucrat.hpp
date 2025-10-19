#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class   Bureaucrat
{
public :
    Bureaucrat(void);
    Bureaucrat(std::string n, unsigned int g);
    ~Bureaucrat(void);

    std::string     getName(void);
    unsigned int    getGrade(void);
    void            incr(void);
    void            decr(void);

    void            signForm(Form &f);

    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    std::string const m_name;
    unsigned int m_grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &bc);

#endif