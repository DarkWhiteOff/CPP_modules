#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return ;
}

PmergeMe::PmergeMe(std::string str)
{
    return ;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        
    }
    return (*this);
}

PmergeMe::~PmergeMe(void)
{
    return ;
}

// void PmergeMe::calc()
// {

// }

const char *PmergeMe::ValueTooLargeException::what(void) const throw()
{
    return ("Error: Value is too large.");
}

const char *PmergeMe::BadInputException::what(void) const throw()
{
    return ("Error");
}