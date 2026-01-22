#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <map>
#include <fstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    std::ifstream file("data.csv");
    if (!file)
        throw FileFailedException();
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        int pos = line.find(',');
        std::string date = line.substr(0, pos);
        std::string ratestr = line.substr(pos + 1);
        float rate = static_cast<float>(std::atof(ratestr.c_str()));
        m_map[date] = rate;
    }
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


void BitcoinExchange::isValidInput(std::string line, std::string date, std::string valuestr)
{
    if (date.empty())
        throw BitcoinExchange::BadInputException(line);
    for (int i = 0; date[i]; i++)
    {
        if ((i == 4 || i == 7) && date[i] == '-')
            continue;
        if (!std::isdigit(date[i]))
            throw BitcoinExchange::BadInputException(date);
    }
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());
    if (m < 1 || m > 12 || d < 1 || d > 31)
        throw BitcoinExchange::BadInputException(date);

    if (valuestr.empty())
        throw BitcoinExchange::BadInputException(line);
    size_t i = 0;
    if (valuestr[0] == '-')
        i++;
    for (; i < valuestr.size(); i++)
    {
        if (valuestr[i] != '.' && !std::isdigit(valuestr[i]))
            throw BitcoinExchange::BadInputException(line);
    }
    float value = static_cast<float>(std::atof(valuestr.c_str()));
    if (value < 0 || value > 1000)
        throw BitcoinExchange::WrongValueException(value);
}

void BitcoinExchange::make(std::string inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file)
        throw FileFailedException();
    std::string line;
    std::getline(file, line);
    try
    {
        if (line.empty() && !std::getline(file, line))
            throw EmptyFileException();
        if (line[line.size() - 1] == '\r')
                line.erase(line.size() - 1);
        if (line != "date | value")
            throw BadInputException(line);
    }
    catch (std::exception &o)
    {
        std::cerr << o.what() << std::endl;
    }
    while (std::getline(file, line))
    {
        try
        {
            if (line.empty())
                throw BadInputException(line);
            if (line[line.size() - 1] == '\r')
                line.erase(line.size() - 1);
            size_t pos = line.find('|');
            if (pos == std::string::npos)
                throw BadInputException(line);
            std::string d = line.substr(0, pos);
            std::string v = line.substr(pos + 1);
            if (d.empty() || d.size() != 11 || d[10] != ' ')
                throw BadInputException(line);
            if (v.empty() || v.size() < 2 || v[0] != ' ')
                throw BadInputException(line);
            std::string date = line.substr(0, pos - 1);
            std::string valuestr = line.substr(pos + 2);
            isValidInput(line, date, valuestr);
            float value = static_cast<float>(std::atof(valuestr.c_str()));
            std::map<std::string, float>::iterator it = m_map.find(date);
            if (it != m_map.end())
            {
                float bcval = value * it->second;
                std::cout << it->first << " => " << value << " = " << bcval << std::endl;
            }
            else
            {
                if (date < m_map.begin()->first)
                    throw DateTooLowException();
                it = m_map.lower_bound(date);
                --it;
                float bcval = value * it->second;
                std::cout << date << " => " << value << " = " << bcval << std::endl;
            }
        }
        catch (std::exception &o)
        {
            std::cerr << o.what() << std::endl;
        }
    }
}

const char *BitcoinExchange::FileFailedException::what(void) const throw()
{
    return ("Error: could not open file.");
}

const char *BitcoinExchange::EmptyFileException::what(void) const throw()
{
    return ("Error: file is empty.");
}

BitcoinExchange::BadInputException::BadInputException(std::string str)
{
    m_msg = "Error: bad input => " + str;
}

const char *BitcoinExchange::BadInputException::what(void) const throw()
{
    return (m_msg.c_str());
}

BitcoinExchange::WrongValueException::WrongValueException(float value)
{
    if (value < 0)
        m_msg = "Error: not a positive number.";
    if (value > 1000)
        m_msg = "Error: too large a number.";
}

const char *BitcoinExchange::WrongValueException::what(void) const throw()
{
    return (m_msg.c_str());
}

const char *BitcoinExchange::DateTooLowException::what(void) const throw()
{
    return ("Error: date too low.");
}