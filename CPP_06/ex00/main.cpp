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
        // VALID CHAR
        std::cout << "VALID CHAR" << std::endl;
        ScalarConverter::convert("\'a\'");
        std::cout << std::endl;
        ScalarConverter::convert("\'Z\'");
        std::cout << std::endl;
        ScalarConverter::convert("\'0\'");
        std::cout << std::endl;
        ScalarConverter::convert("\'%\'");
        std::cout << std::endl;
        ScalarConverter::convert("\' \'");
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;
        
        // INVALID CHAR
        std::cout << "INVALID CHAR" << std::endl;
        ScalarConverter::convert("a");
        std::cout << std::endl;
        ScalarConverter::convert("\'\'");
        std::cout << std::endl;
        ScalarConverter::convert("\'ab\'");
        std::cout << std::endl;
        ScalarConverter::convert("\'4a\'");
        std::cout << std::endl;
        ScalarConverter::convert("\'");
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;

        // VALID INT
        std::cout << "INT" << std::endl;
        ScalarConverter::convert("0");
        std::cout << std::endl;
        ScalarConverter::convert("42");
        std::cout << std::endl;
        ScalarConverter::convert("-42");
        std::cout << std::endl;
        ScalarConverter::convert("+99");
        std::cout << std::endl;
        ScalarConverter::convert("2147483647");
        std::cout << std::endl;
        ScalarConverter::convert("-2147483648");
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;

        // INVALID INT
        std::cout << "INVALID INT" << std::endl;
        ScalarConverter::convert("42a");
        std::cout << std::endl;
        ScalarConverter::convert("4.2");
        std::cout << std::endl;
        ScalarConverter::convert("+");
        std::cout << std::endl;
        ScalarConverter::convert("--42");
        std::cout << std::endl;
        ScalarConverter::convert("2147483648");
        std::cout << std::endl;
        ScalarConverter::convert("-2147483649");
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;

        // VALID FLOAT
        std::cout << "FLOAT" << std::endl;
        ScalarConverter::convert("42.0f");
        std::cout << std::endl;
        ScalarConverter::convert("-42.5f");
        std::cout << std::endl;
        ScalarConverter::convert("3.14f");
        std::cout << std::endl;
        ScalarConverter::convert("5.0f");
        std::cout << std::endl;
        ScalarConverter::convert("0.0001f");
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;

        // INVALID FLOAT
        std::cout << "INVALID FLOAT" << std::endl;
        ScalarConverter::convert(".5f");
        std::cout << std::endl;
        ScalarConverter::convert("5.f");
        std::cout << std::endl;
        ScalarConverter::convert("42.fg");
        std::cout << std::endl;
        ScalarConverter::convert("42.");
        std::cout << std::endl;
        ScalarConverter::convert("42");
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;

        // VALID DOUBLE
        std::cout << "VALID DOUBLE" << std::endl;
        ScalarConverter::convert("42.0");
        std::cout << std::endl;
        ScalarConverter::convert("-42.5");
        std::cout << std::endl;
        ScalarConverter::convert("+3.1415");
        std::cout << std::endl;
        ScalarConverter::convert("0.01");
        std::cout << std::endl;
        ScalarConverter::convert("5.000");
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << std::endl;

        // INVALID DOUBLE
        std::cout << "INVALID DOUBLE" << std::endl;
        ScalarConverter::convert(".5");
        std::cout << std::endl;
        ScalarConverter::convert("5.");
        std::cout << std::endl;
        ScalarConverter::convert("42");
        std::cout << std::endl;
        ScalarConverter::convert("42.0f");
        std::cout << std::endl;
        ScalarConverter::convert("4.2.3");
    }
    return (0);
}