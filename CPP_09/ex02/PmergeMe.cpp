#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return ;
}

PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        std::stringstream ss(argv[i]);
        int value;
        if (!(ss >> value) || !(ss.eof()) || value < 0)
            throw BadInputException();
        m_v.push_back(value);
        m_d.push_back(value);
    }
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
    (*this) = copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
    if (this != &src)
    {
        m_v = src.m_v;
        m_d = src.m_d;
    }
    return (*this);
}

PmergeMe::~PmergeMe(void)
{
    return ;
}

void PmergeMe::sortVector()
{
    if (m_v.size() <= 1)
        return;
    std::vector<int> copy = m_v;
    std::vector<int> big;
    std::vector<int> small;
    big.reserve(copy.size() / 2);
    small.reserve(copy.size() / 2);
    size_t i = 0;
    for (; i + 1 < copy.size(); i += 2)
    {
        int a = copy[i];
        int b = copy[i + 1];
        if (a > b)
            std::swap(a, b);
        small.push_back(a);
        big.push_back(b);
    }
    bool hasLeftover = (i < copy.size());
    int leftover = 0;
    if (hasLeftover)
        leftover = copy[i];
    // std::sort(big.begin(), big.end());
    // std::vector<int> mainChain = big;
    m_v = big;
    sortVector();
    std::vector<int> mainChain = m_v;
    for (size_t j = 0; j < small.size(); ++j)
    {
        int value = small[j];
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(it, value);
    }
    if (hasLeftover)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(it, leftover);
    }
    m_v = mainChain;
}
    
void PmergeMe::sortDeque()
{
    if (m_d.size() <= 1)
        return;
    std::deque<int> copy = m_d;
    std::deque<int> big;
    std::deque<int> small;
    size_t i = 0;
    for (; i + 1 < copy.size(); i += 2)
    {
        int a = copy[i];
        int b = copy[i + 1];
        if (a > b)
            std::swap(a, b);
        small.push_back(a);
        big.push_back(b);
    }
    bool hasLeftover = (i < copy.size());
    int leftover = 0;
    if (hasLeftover)
        leftover = copy[i];
    // std::vector<int> mainChain(big.begin(), big.end());
    // std::sort(mainChain.begin(), mainChain.end());
    m_d = big;
    sortDeque();
    std::vector<int> mainChain(m_d.begin(), m_d.end());
    for (size_t j = 0; j < small.size(); ++j)
    {
        int value = small[j];
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(it, value);
    }
    if (hasLeftover)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(it, leftover);
    }
    m_d.assign(mainChain.begin(), mainChain.end());
}

void PmergeMe::make()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < m_v.size(); i++)
        std::cout << m_v[i] << " ";
    std::cout << std::endl;

    clock_t stVec = clock();
    sortVector();
    clock_t endVec = clock();
    clock_t stDeq = clock();
    sortDeque();
    clock_t endDeq = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < m_v.size(); i++)
        std::cout << m_v[i] << " ";
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - stVec) / CLOCKS_PER_SEC * 1000000.0;
    double timeDeq = static_cast<double>(endDeq - stDeq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "Time to process a range of "
          << m_v.size()
          << " elements with std::vector : "
          << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of "
          << m_d.size()
          << " elements with std::deque : "
          << timeDeq << " us" << std::endl;
}

const char *PmergeMe::BadInputException::what(void) const throw()
{
    return ("Error");
}