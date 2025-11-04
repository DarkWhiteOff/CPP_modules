#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <>
#include <algorithm>
#include <sstream>

class PmergeMe
{
public :
    PmergeMe(void);
    PmergeMe(std::string str);
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe(void);

    // void calc();

    class ValueTooLargeException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class BadInputException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    
};

#endif