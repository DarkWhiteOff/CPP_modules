#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
public :
    Form(void);
    Form(std::string const n, unsigned int gs, unsigned int ge);
    ~Form(void);

    Form(Form const &copy);
    Form &operator=(Form const &src);

    std::string const getName(void) const;
    bool getSigned(void) const;
    unsigned int getGradeSign(void) const;
    unsigned int getGradeExec(void) const;

    void beSigned(Bureaucrat const &b);

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

    class AlreadySignedException : public std::exception
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

std::ostream &operator<<(std::ostream &output, Form const &obj);

#endif