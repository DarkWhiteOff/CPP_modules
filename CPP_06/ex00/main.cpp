#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    ScalarConverter::convert(argv[1]);
    return (0);
}