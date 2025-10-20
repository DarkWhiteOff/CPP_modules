#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    return ;
}

BitcoinExchange::BitcoinExchange(unsigned int N)
{
    return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
    return ;
}

const char *BitcoinExchange::SpanIsFullException::what(void) const throw()
{
    return ("Span Is Full!\n");
}