#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <exception>
#include <map>

class BitcoinExchange
{
public :
    BitcoinExchange(void);
    BitcoinExchange(BitcoinExchange const &copy);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange(void);

    void make(std::string const &inputFile);

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
            BadInputException(const std::string &str);
            virtual ~BadInputException() throw();
            virtual const char *what(void) const throw();
        private :
            std::string m_msg;
    };

    class WrongValueException : public std::exception
    {
        public :
            WrongValueException(float value);
            virtual ~WrongValueException() throw();
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

    void loadDatabase(std::string const &dbFile);

    void parseLine(std::string const &line, std::string &date, std::string &valuestr);

    bool isValidDate(std::string const &date);
    int  daysInMonth(int m);
    bool isValidValue(std::string const &valuestr, float &value);
    void isValidInput(std::string const &line, std::string const &date, std::string const &valuestr);

    float getRateForDate(std::string const &date);
};

#endif