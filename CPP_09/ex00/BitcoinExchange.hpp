#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
public :
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange(void);

    void make(std::string inputFile);

    class FileFailedException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class BadInputException : public std::exception
    {
        public :
            BadInputException(std::string date);
            virtual ~BadInputException() throw() {}
            virtual const char *what(void) const throw();
        private :
            std::string m_msg;
    };

    class BadInput1Exception : public std::exception
    {
        public :
            BadInput1Exception(std::string line);
            virtual ~BadInput1Exception() throw() {}
            virtual const char *what(void) const throw();
        private :
            std::string m_msg;
    };

    class WrongValueException : public std::exception
    {
        public :
            WrongValueException(float value);
            virtual ~WrongValueException() throw() {}
            virtual const char *what(void) const throw();
        private :
            std::string m_msg;
    };

private :
    std::map<std::string, float> m_map;
};

#endif