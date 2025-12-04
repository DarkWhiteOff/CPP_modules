#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
    {
        // CHAR
        std::cout << "CHAR" << std::endl;
        ScalarConverter::convert("\'a\'");
        ScalarConverter::convert("\'Z\'");
        ScalarConverter::convert("\'0\'");
        ScalarConverter::convert("\'%\'");
        ScalarConverter::convert("\' \'");
        ScalarConverter::convert("\'\n\'");

        // INT
        std::cout << "INT" << std::endl;
        ScalarConverter::convert("0");
        ScalarConverter::convert("42");
        ScalarConverter::convert("-42");
        ScalarConverter::convert("+99");
        ScalarConverter::convert("2147483647");
        ScalarConverter::convert("-2147483648");

        // FLOAT
        std::cout << "FLOAT" << std::endl;
        ScalarConverter::convert("1.0f");
        ScalarConverter::convert("42.5f");
        ScalarConverter::convert("0.0f");
        ScalarConverter::convert("-0.5f");
        ScalarConverter::convert(".5f");
        ScalarConverter::convert("5.f");
        ScalarConverter::convert("+4.2f");
        ScalarConverter::convert("-4.2f");
    }
    return (0);
}