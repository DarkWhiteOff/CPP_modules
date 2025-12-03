#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void) src;
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
    return ;
}

bool isPrintableChar(char c)
{
    if (c >= 32 && c <= 126)
        return true;
    return false;
}

bool isQuotedChar(std::string s)
{
    if (s.size() == 3 && s[0] == '\'' && s[2] == '\'' && isPrintableChar(s[1]))
        return true;
    return false;
}

bool isPseudo(std::string s)
{
    if (s == "nan" || s == "+inf" || s == "-inf" ||
           s == "nanf" || s == "+inff" || s == "-inff")
        return true;
    return false;
}

bool isInt(std::string s)
{
    size_t i = 0;
    if (s[0] == '-')
        i++;
    for (i; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool isAllDigits(std::string s, size_t a, size_t b) {
    for (size_t i = a; i < b; ++i)
        if (!isdigit(s[i]))
            return false;
    return true;
}

bool isFloat(std::string s)
{
    if (s.size() < 4)
        return false;
    if (s[s.size()-1] != 'f')
        return false;
    std::string core = s.substr(0, s.size()-1);

    size_t i = 0;
    if (core[0] == '-')
        i++;

    size_t dot = core.find('.');
    if (dot == std::string::npos)
        return false;

    bool leftOk = false;
    bool rightOk = false;
    if (isAllDigits(core, i, dot))
        leftOk = true;
    if (isAllDigits(core, dot + 1, core.size()))
        rightOk = true;
    if (leftOk && rightOk)
        return true;
    return false;
}

bool isDouble(std::string s)
{
    if (s.size() < 3)
        return false;
    size_t i = 0;
    if (s[0] == '-')
        i++;

    size_t dot = s.find('.');
    if (dot == std::string::npos)
        return false;

    bool leftOk = false;
    bool rightOk = false;
    if (isAllDigits(s, i, dot))
        leftOk = true;
    if (isAllDigits(s, dot + 1, s.size()))
        rightOk = true;
    if (leftOk && rightOk)
        return true;
    return false;
}

LiteralType detectType(std::string s) {
    if (isQuotedChar(s))
        return T_CHAR;
    if (isPseudo(s))
        return T_PSEUDO;
    if (isInt(s))
        return T_INT;
    if (isFloat(s))
        return T_FLOAT;
    if (isDouble(s))
        return T_DOUBLE;
    return T_INVALID;
}

void ScalarConverter::convert(std::string str)
{
    LiteralType type = detectType(str);

    double value = 0.0;

    if (type == T_CHAR)
        value = static_cast<double>(str[1]);
    else if (type == T_INT)
        value = static_cast<double>(std::stoi(str));
    else if (type == T_FLOAT)
        value = static_cast<double>(std::stof(str));
    else if (type == T_DOUBLE)
        value = std::stod(str);
    else if (type == T_PSEUDO)
    {
        if (str == "nan" || str == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (str == "+inf" || str == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (str == "-inf" || str == "-inff")
            value = -std::numeric_limits<double>::infinity();
    }
    else
        std::cout << "Invalid str\n" << std::endl;

    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;


    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
