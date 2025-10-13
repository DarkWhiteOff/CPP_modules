#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class   Bureaucrat
{
public :
    Bureaucrat(void);
    Bureaucrat(std::string n);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat(void);
    void    getName(void);
    void    getGrade(void);

    Bureaucrat operator++(int);
    Bureaucrat operator--(int);

private :
    std::string const m_name;
    int m_grade;
};

#endif