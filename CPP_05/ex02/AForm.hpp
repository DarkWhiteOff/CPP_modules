#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm
{
public :
    AForm(void);
    AForm(std::string const n, std::string const t, unsigned int gs, unsigned int ge);
    virtual ~AForm(void);

    std::string const getTarget(void) const;

    std::string const getName(void) const;
    bool getSigned(void) const;
    unsigned int getGradeSign(void) const;
    unsigned int getGradeExec(void) const;

    void beSigned(Bureaucrat const &b);
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
    std::string const m_target;
    bool m_signed;
    unsigned int const m_grade_sign;
    unsigned int const m_grade_exe;
};

std::ostream &operator<<(std::ostream &output, AForm const &obj);

#endif