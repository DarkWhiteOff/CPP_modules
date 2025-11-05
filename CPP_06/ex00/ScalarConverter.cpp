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

static bool isPrintableChar(char c) { return c >= 32 && c <= 126; }

bool ScalarConverter::isQuotedChar(std::string s)
{
    return s.size() == 3 && s[0] == '\'' && s[2] == '\'' && isPrintableChar(s[1]);
}

bool ScalarConverter::isPseudoLiteral(std::string s)
{
    return s == "nan" || s == "+inf" || s == "-inf" ||
           s == "nanf" || s == "+inff" || s == "-inff";
}

bool ScalarConverter::isIntLiteral(std::string s)
{
    size_t i = 0;
    if (s[0] == '-')
        i++;
    for (; i < s.size(); ++i)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

static bool isAllDigits(std::string s, size_t a, size_t b) {
    for (size_t i = a; i < b; ++i)
        if (!isdigit(s[i]))
            return false;
    return true;
}

bool ScalarConverter::isFloatLiteral(std::string s)
{
    if (s.size() < 2)
        return false;
    if (s[s.size()-1] != 'f')
        return false;
    std::string core = s.substr(0, s.size()-1);

    size_t i = 0;
    if (core[0] == '-')
        i++;
    if (i == core.size())
        return false;

    size_t dot = core.find('.');
    if (dot == std::string::npos)
        return false;

    bool leftOk  = (dot > i) ? isAllDigits(core, i, dot) : false;
    bool rightOk = (dot + 1 < core.size()) ? isAllDigits(core, dot+1, core.size()) : false;
    return leftOk || rightOk;
}

bool ScalarConverter::isDoubleLiteral(std::string s)
{
    size_t i = 0;
    if (s[0] == '-')
    {
        i++;
        if (i == s.size())
            return false;
    }

    size_t dot = s.find('.');
    if (dot == std::string::npos)
        return false;

    bool leftOk  = (dot > i) ? isAllDigits(s, i, dot) : false;
    bool rightOk = (dot + 1 < s.size()) ? isAllDigits(s, dot+1, s.size()) : false;
    return leftOk || rightOk;
}


void ScalarConverter::convert(std::string literal)
{
    LiteralType type = detectType(literal);

    double value = 0.0;

    if (type == T_CHAR)
        value = static_cast<double>(literal[1]);
    else if (type == T_INT)
        value = static_cast<double>(std::stoi(literal));
    else if (type == T_FLOAT)
        value = static_cast<double>(std::stof(literal));
    else if (type == T_DOUBLE)
        value = std::stod(literal);
    else if (type == T_PSEUDO)
    {
        if (literal == "nan" || literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
    }
    else
        std::cout << "Invalid literal\n" << std::endl;


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

LiteralType ScalarConverter::detectType(std::string s) {
    if (isQuotedChar(s))        return T_CHAR;
    if (isPseudoLiteral(s))     return T_PSEUDO;
    if (isIntLiteral(s))        return T_INT;
    if (isFloatLiteral(s))      return T_FLOAT;
    if (isDoubleLiteral(s))     return T_DOUBLE;
    return T_INVALID;
}
