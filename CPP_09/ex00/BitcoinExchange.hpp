#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <map>
#include <fstream>

class BitcoinExchange
{
public :
    BitcoinExchange(void);
    BitcoinExchange(BitcoinExchange const &copy);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange(void);

    void make(std::string inputFile);

    class FileFailedException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

    class EmptyFileException : public std::exception
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

    class WrongValueException : public std::exception
    {
        public :
            WrongValueException(float value);
            virtual ~WrongValueException() throw() {}
            virtual const char *what(void) const throw();
        private :
            std::string m_msg;
    };

    class DateTooLowException : public std::exception
    {
        public :
            virtual const char *what(void) const throw();
    };

private :
    std::map<std::string, float> m_map;
};

#endif