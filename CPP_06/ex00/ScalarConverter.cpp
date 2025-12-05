#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include "ScalarConverter.hpp"

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

bool ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool isInt(std::string s)
{
    size_t i = 0;
    if (s[0] == '-')
        i++;
    for (; i < s.size(); i++)
    {
        if (!ft_isdigit(s[i]))
            return false;
    }
    return true;
}

bool isAllDigits(std::string s, size_t a, size_t b)
{
    if (a >= b)
        return false;
    for (size_t i = a; i < b; ++i)
        if (!ft_isdigit(s[i]))
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

Type detectType(std::string s)
{
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

bool ft_isNan(double v)
{
    if (v != v)
        return true;
    return false;
}

bool ft_isInf(double v)
{
    double max = std::numeric_limits<double>::max();
    if (!ft_isNan(v) && (v > max || v < -max))
        return true;
    return false;
}

void ScalarConverter::convert(std::string str)
{
    if (str.empty())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (str.size() > 1 && str[0] == '+' && isdigit(str[1]))
        str = str.substr(1);
    Type type = detectType(str);
    double value = 0.0;

    if (type == T_CHAR)
        value = str[1];
    else if (type == T_INT || type == T_FLOAT || type == T_DOUBLE)
        value = std::strtod(str.c_str(), NULL);
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
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (ft_isNan(value) || ft_isInf(value) ||
        value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max() || (static_cast<char>(value)) < 0)
        std::cout << "impossible" << std::endl;
    else if (!isPrintableChar(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: ";
    if (ft_isNan(value) || ft_isInf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    
    std::cout << "float: ";
    if (ft_isNan(value))
        std::cout << "nanf" << std::endl;
    else if (ft_isInf(value))
        std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

    std::cout << "double: ";
    if (ft_isNan(value))
        std::cout << "nan" << std::endl;
    else if (ft_isInf(value))
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}