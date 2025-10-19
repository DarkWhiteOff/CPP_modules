#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm
{
public :
    AForm(void);
    AForm(std::string n, unsigned int gs, unsigned int ge);
    virtual ~AForm(void);

    void            setTarget(std::string t);
    std::string     getName(void) const;
    std::string     getTarget(void) const;
    bool            getSigned(void) const;
    unsigned int    getGradeSign(void);
    unsigned int    getGradeExec(void) const;

    virtual void    beSigned(Bureaucrat &b);

    virtual void execute(Bureaucrat const &executor) const = 0;

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

    class FormNotSignedException : public std::exception
    {
        public :
            const char *what() const throw();
    };

private :
    std::string const m_name;
    std::string m_target;
    bool m_signed;
    unsigned int const m_grade_sign;
    unsigned int const m_grade_exe;
};

std::ostream &operator<<(std::ostream &os, AForm &f);

#endif