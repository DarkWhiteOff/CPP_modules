#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class   Bureaucrat
{
public :
    Bureaucrat(void);
    Bureaucrat(std::string n, unsigned int g);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat(void);
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
    unsigned int m_grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj);

#endif