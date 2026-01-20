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
        if (!(ss >> value) || !(ss.eof()) || value <= 0)
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

std::vector<size_t> PmergeMe::buildJacobOrder(size_t m)
{
    std::vector<size_t> order;
    if (m <= 1)
        return order;

    size_t prev = 1;
    size_t j0 = 1, j1 = 3;

    while (j1 <= m)
    {
        order.push_back(j1);

        for (size_t k = j1 - 1; k > prev; k--)
            order.push_back(k);

        prev = j1;

        size_t next = j1 + 2 * j0;            // Jacobsthal: J(n)=J(n-1)+2*J(n-2)
        j0 = j1;
        j1 = next;
    }

    for (size_t k = m; k > prev; k--)
        order.push_back(k);

    return order;
}

void PmergeMe::sortVector()
{
    if (m_v.size() <= 1)
        return;

    std::vector<Pair> pairs;
    pairs.reserve(m_v.size() / 2);

    size_t i = 0;
    for (; i + 1 < m_v.size(); i += 2)
    {
        int a = m_v[i];
        int b = m_v[i + 1];
        if (a > b)
            std::swap(a, b);
        Pair p; p.small = a; p.big = b;
        pairs.push_back(p);
    }
    bool hasLeftover = (i < m_v.size());
    int leftover = 0;
    if (hasLeftover)
        leftover = m_v[i];

    std::vector<int> big;
    big.reserve(pairs.size());
    for (size_t k = 0; k < pairs.size(); k++)
        big.push_back(pairs[k].big);
    m_v = big;
    sortVector();

    std::vector<Pair> sortedPairs;
    sortedPairs.reserve(pairs.size());
    for (size_t k = 0; k < m_v.size(); k++)
    {
        int targetBig = m_v[k];
        for (size_t p = 0; p < pairs.size(); p++)
        {
            if (pairs[p].big == targetBig)
            {
                sortedPairs.push_back(pairs[p]);
                pairs.erase(pairs.begin() + p);
                break;
            }
        }
    }

    std::vector<int> mainChain = m_v;
    int b1 = sortedPairs[0].small;
    mainChain.insert(mainChain.begin(), b1);

    std::vector<size_t> order = buildJacobOrder(sortedPairs.size());
    for (size_t t = 0; t < order.size(); t++)
    {
        size_t idx = order[t];
        int value = sortedPairs[idx - 1].small;
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }
    if (hasLeftover)
    {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(it, leftover);
    }
    m_v = mainChain;
}
    
void PmergeMe::sortDeque()
{
    if (m_d.size() <= 1)
        return;

    std::vector<Pair> pairs;
    pairs.reserve(m_d.size() / 2);

    size_t i = 0;
    for (; i + 1 < m_d.size(); i += 2)
    {
        int a = m_d[i];
        int b = m_d[i + 1];
        if (a > b)
            std::swap(a, b);
        Pair p; p.small = a; p.big = b;
        pairs.push_back(p);
    }
    bool hasLeftover = (i < m_d.size());
    int leftover = 0;
    if (hasLeftover)
        leftover = m_d[i];

    std::deque<int> big;
    for (size_t k = 0; k < pairs.size(); k++)
        big.push_back(pairs[k].big);
    m_d = big;
    sortDeque();

    std::vector<Pair> sortedPairs;
    sortedPairs.reserve(pairs.size());
    for (size_t k = 0; k < m_d.size(); k++)
    {
        int targetBig = m_d[k];
        for (size_t p = 0; p < pairs.size(); p++)
        {
            if (pairs[p].big == targetBig)
            {
                sortedPairs.push_back(pairs[p]);
                pairs.erase(pairs.begin() + p);
                break;
            }
        }
    }

    std::vector<int> mainChain(m_d.begin(), m_d.end());
    int b1 = sortedPairs[0].small;
    mainChain.insert(mainChain.begin(), b1);

    std::vector<size_t> order = buildJacobOrder(sortedPairs.size());
    for (size_t t = 0; t < order.size(); t++)
    {
        size_t idx = order[t];
        int value = sortedPairs[idx - 1].small;

        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    if (hasLeftover)
    {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
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