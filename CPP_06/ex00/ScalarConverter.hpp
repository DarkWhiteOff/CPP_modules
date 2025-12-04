#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

enum LiteralType {T_CHAR, T_INT, T_FLOAT, T_DOUBLE, T_PSEUDO, T_INVALID};

class ScalarConverter
{
public :
    static void convert(std::string str);
private :
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &src);
    ~ScalarConverter(void);
};

#endif