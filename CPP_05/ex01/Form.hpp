#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
public :
    Form(void);
    Form(std::string n, unsigned int gs, unsigned int ge);
    ~Form(void);

    std::string     getName(void);
    bool            getSigned(void);
    unsigned int    getGradeSign(void);
    unsigned int    getGradeExec(void);

    void            beSigned(Bureaucrat &b);

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
    bool m_signed;
    unsigned int const m_grade_sign;
    unsigned int const m_grade_exe;
};

std::ostream &operator<<(std::ostream &os, Form &f);

#endif