#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
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
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &src);
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