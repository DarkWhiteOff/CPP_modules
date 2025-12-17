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

static std::vector<size_t> buildJacobInsertionOrder(size_t m)
{
    std::vector<size_t> order;
    if (m <= 1)
        return order; // b1 déjà géré ailleurs

    // Génère Jacobsthal: 0,1,1,3,5,11,21...
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);
    while (true)
    {
        size_t n = J.size();
        size_t next = J[n - 1] + 2 * J[n - 2];
        if (next > m)
            break;
        J.push_back(next);
    }

    size_t prev = 1; // parce que b1 sera déjà inséré
    // on démarre à l'indice 3 dans Jacobsthal (valeur 3)
    for (size_t i = 0; i < J.size(); i++)
    {
        size_t j = J[i];
        if (j < 3)
            continue;
        if (j > m)
            break;

        order.push_back(j);
        for (size_t k = j - 1; k > prev; k--)
            order.push_back(k);

        prev = j;
    }

    for (size_t k = m; k > prev; k--)
        order.push_back(k);

    return order; // indices 1-based (b1..bm)
}

void PmergeMe::sortVector()
{
    if (m_v.size() <= 1)
        return;
    std::vector<int> big;
    std::vector<int> small;
    big.reserve(m_v.size() / 2);
    small.reserve(m_v.size() / 2);
    size_t i = 0;
    for (; i + 1 < m_v.size(); i += 2)
    {
        int a = m_v[i];
        int b = m_v[i + 1];
        if (a > b)
            std::swap(a, b);
        small.push_back(a);
        big.push_back(b);
    }
    bool hasLeftover = (i < m_v.size());
    int leftover = 0;
    if (hasLeftover)
        leftover = m_v[i];
    m_v = big;
    sortVector();
    std::vector<int> mainChain = m_v;
    // for (size_t j = 0; j < small.size(); j++)
    // {
    //     int value = small[j];
    //     std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    //     mainChain.insert(it, value);
    // }
    if (!small.empty())
    {
        // b1 en premier (a push si <= au premier big donc a faire)
        int b1 = small[0];
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), b1);
        mainChain.insert(it, b1);

        // ordre Jacobsthal pour b2..bm
        std::vector<size_t> order = buildJacobInsertionOrder(small.size());
        for (size_t t = 0; t < order.size(); t++)
        {
            size_t idx = order[t];          // 1-based
            int value = small[idx - 1];     // small[1] = b2, etc.
            std::vector<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
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
    m_d = big;
    sortDeque();
    std::vector<int> mainChain(m_d.begin(), m_d.end());
    for (size_t j = 0; j < small.size(); j++)
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