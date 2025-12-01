#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class   Bureaucrat
{
public :
    Bureaucrat(void);
    Bureaucrat(std::string const n, unsigned int g);
    ~Bureaucrat(void);

    std::string const getName(void) const;
    unsigned int getGrade(void) const;
    void incr(void);
    void decr(void);

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

std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj);

#endif