#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <exception>
#include <vector>
#include <deque>
#include <cstddef>

struct Pair
{
    int small;
    int big;
};

class PmergeMe
{
public :
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

    PmergeMe(void);

    std::vector<size_t> buildJacobOrder(size_t m);
    void sortVector();
    void sortDeque();

    std::vector<int> recursiveSortVector(std::vector<int> const &in);
    std::deque<int>  recursiveSortDeque (std::deque<int> const &in);
};

#endif