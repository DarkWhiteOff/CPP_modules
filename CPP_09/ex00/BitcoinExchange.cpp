#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    std::ifstream file("data.csv");
    if (!file)
        throw FileFailedException();
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        int pos = line.find(',');
        std::string date = line.substr(0, pos);
        std::string ratestr = line.substr(pos + 1);
        float rate = std::stof(ratestr);
        m_map.insert({date, rate});
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
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


void isValidInput(std::string line, std::string date, float value)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw BitcoinExchange::BadInputException(date);

    int m = std::stoi(date.substr(5, 2));
    int d = std::stoi(date.substr(8, 2));

    if (m < 1 || m > 12 || d < 1 || d > 31)
        throw BitcoinExchange::BadInputException(date);
    if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        throw BitcoinExchange::BadInput1Exception(line);
    if (value < 0 || value > 1000)
        throw BitcoinExchange::WrongValueException(value);
}

void BitcoinExchange::make(std::string inputFile)
{
    std::ifstream file(inputFile);
    if (!file)
        throw FileFailedException();
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        try
        {
            size_t pos = line.find('|');
            if (pos == std::string::npos)
                throw BadInput1Exception(line);
            std::string date = line.substr(0, pos - 1);
            std::string valuestr = line.substr(pos + 2);
            float value = std::stof(valuestr);
            isValidInput(line, date, value);
            std::map<std::string, float>::iterator it = m_map.find(date);
            if (it != m_map.end())
            {
                float bcval = value * it->second;
                std::cout << it->first << " => " << value << " = " << bcval << std::endl;
            }
            else
            {
                it = m_map.lower_bound(date);
                --it;
                float bcval = value * it->second;
                std::cout << it->first << " => " << value << " = " << bcval << std::endl;
            }
        }
        catch (std::exception &o)
        {
            std::cout << o.what() << std::endl;
        }
    }
}

const char *BitcoinExchange::FileFailedException::what(void) const throw()
{
    return ("Error: could not open file.");
}

BitcoinExchange::BadInputException::BadInputException(std::string date)
{
    m_msg = "Error: bad input => " + date;
}

const char *BitcoinExchange::BadInputException::what(void) const throw()
{
    return (m_msg.c_str());
}

BitcoinExchange::BadInput1Exception::BadInput1Exception(std::string line)
{
    m_msg = "Error: bad input => " + line;
}

const char *BitcoinExchange::BadInput1Exception::what(void) const throw()
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