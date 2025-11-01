#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
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
        private :
            std::string m_msg;
        public :
            BadInputException(std::string date);
            virtual const char *what(void) const throw();
    };

    class BadInput1Exception : public std::exception
    {
        private :
            std::string m_msg;
        public :
            BadInput1Exception(std::string line);
            virtual const char *what(void) const throw();
    };

    class WrongValueException : public std::exception
    {
        private :
            std::string m_msg;
        public :
            WrongValueException(float value);
            virtual const char *what(void) const throw();
    };

private :
    std::map<std::string, float> m_map;
};

#endif