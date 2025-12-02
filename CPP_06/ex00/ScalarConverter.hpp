#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>

enum LiteralType {T_CHAR, T_INT, T_FLOAT, T_DOUBLE, T_PSEUDO, T_INVALID};

class ScalarConverter
{
public :
    static LiteralType detectType(std::string s);
    static void convert(std::string literal);
private :
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &src);
    ~ScalarConverter(void);

    static bool isQuotedChar(std::string s);
    static bool isIntLiteral(std::string s);
    static bool isFloatLiteral(std::string s);
    static bool isDoubleLiteral(std::string s);
    static bool isPseudoLiteral(std::string s);
};

#endif