#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sstream>

class PmergeMe
{
public :
    PmergeMe(void);
    PmergeMe(char **argv);
    PmergeMe(PmergeMe const &copy);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe(void);

    void make();

    class BadInputException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    std::vector<int> m_v;
    std::deque<int> m_d;

    void sortVector();
    void sortDeque();
};

#endif