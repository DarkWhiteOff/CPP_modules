#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void)
{
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
    (*this) = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
    {
        m_map = src.m_map;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
    return ;
}

const char *BitcoinExchange::FileFailedException::what() const throw()
{
    return "Error: could not open file.";
}

const char *BitcoinExchange::EmptyFileException::what() const throw()
{
    return "Error: file is empty.";
}

BitcoinExchange::BadInputException::BadInputException(const std::string &str)
    : m_msg("Error: bad input => " + str) {}

BitcoinExchange::BadInputException::~BadInputException() throw() {}

const char *BitcoinExchange::BadInputException::what() const throw()
{
    return m_msg.c_str();
}

BitcoinExchange::WrongValueException::WrongValueException(float value)
{
    if (value < 0)
        m_msg = "Error: not a positive number.";
    else
        m_msg = "Error: too large a number.";
}

BitcoinExchange::WrongValueException::~WrongValueException() throw() {}

const char *BitcoinExchange::WrongValueException::what() const throw()
{
    return m_msg.c_str();
}

const char *BitcoinExchange::DateTooLowException::what() const throw()
{
    return "Error: date too low.";
}

void BitcoinExchange::loadDatabase(std::string const &dbFile)
{
    std::ifstream file(dbFile.c_str());
    if (!file)
        throw FileFailedException();

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        std::string::size_type pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std::string date = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);

        float rate = static_cast<float>(std::atof(rateStr.c_str()));
        m_map[date] = rate;
    }
}

void BitcoinExchange::parseLine(std::string const &line, std::string &date, std::string &valuestr)
{
    if (line.size() < 14)
        throw BadInputException(line);
    size_t pos = line.find('|');
    if (pos == std::string::npos)
        throw BadInputException(line);
    if (pos != 11 || line[pos - 1] != ' ' || line[pos + 1] != ' ')
        throw BadInputException(line);

    date = line.substr(0, 10);
    valuestr = line.substr(pos + 2);

    for (size_t i = 0; i < date.size(); i++)
    {
        if (date[i] == ' ')
            throw BadInputException(line);
    }
    for (size_t i = 0; i < valuestr.size(); i++)
    {
        if (valuestr[i] == ' ')
            throw BadInputException(line);
    }
}

int BitcoinExchange::daysInMonth(int m)
{
    int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return mdays[m - 1];
}

bool BitcoinExchange::isValidDate(std::string const &date)
{
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (!std::isdigit(static_cast<unsigned char>(date[i])))
                return false;
        }
    }

    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());
    if (m < 1 || m > 12)
        return false;
    int maxDay = daysInMonth(m);
    if (d < 1 || d > maxDay)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(std::string const &valuestr, float &value)
{
    bool seenDot = false;
    bool seenDigit = false;

    for (size_t i = 0; i < valuestr.size(); i++)
    {
        char c = valuestr[i];

        if (c == '+' || c == '-')
        {
            if (i != 0 || valuestr.size() == 1)
                return false;
        }
        else if (c == '.')
        {
            if (seenDot)
                return false;
            if (i == 0 || i == valuestr.size() - 1)
                return false;
            seenDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(c)))
            seenDigit = true;
        else
            return false;
    }
    if (!seenDigit)
        return false;

    value = static_cast<float>(std::atof(valuestr.c_str()));
    return true;
}

void BitcoinExchange::isValidInput(std::string const &line, std::string const &date, std::string const &valuestr)
{
    if (!isValidDate(date))
        throw BadInputException(date);

    float value = 0.0;
    if (!isValidValue(valuestr, value))
        throw BadInputException(line);
    if (value < 0 || value > 1000)
        throw WrongValueException(value);
}

float BitcoinExchange::getRateForDate(std::string const &date)
{
    std::map<std::string, float>::iterator it = m_map.find(date);
    if (it != m_map.end())
        return it->second;

    it = m_map.lower_bound(date);
    --it;
    return it->second;
}

void BitcoinExchange::make(std::string const &inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file)
        throw FileFailedException();

    std::string line;
    if (!std::getline(file, line))
        throw EmptyFileException();

    if (!line.empty() && line[line.size() - 1] == '\r')
        line.erase(line.size() - 1);
    if (line != "date | value")
        std::cerr << "Error: bad input => " << line << std::endl;

    while (std::getline(file, line))
    {
        try
        {
            if (!line.empty() && line[line.size() - 1] == '\r')
                line.erase(line.size() - 1);
            if (line.empty())
                throw BadInputException(line);
            
            std::string date, valuestr;
            parseLine(line, date, valuestr);
            isValidInput(line, date, valuestr);
            float value = static_cast<float>(std::atof(valuestr.c_str()));

            if (!m_map.empty() && date < m_map.begin()->first)
                throw DateTooLowException();
            float rate = getRateForDate(date);
            float result = value * rate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (std::exception &o)
        {
            std::cerr << o.what() << std::endl;
        }
    }
}