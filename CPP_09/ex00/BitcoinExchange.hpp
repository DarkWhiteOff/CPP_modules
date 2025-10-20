#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

class BitcoinExchange
{
public :
    BitcoinExchange(void);
    BitcoinExchange(unsigned int N);
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange(void);

    class SpanIsFullException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    
};

#endif