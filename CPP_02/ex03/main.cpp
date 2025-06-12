#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    //TEST TRUE
    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(1.86, 3.88)) == true) // True
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    //TESTS FALSE
    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(-2.8, 2.5)) == true) // False
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(1.78, 4)) == true) // False
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(2, 2.3)) == true) // False
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(1.4, -3.76)) == true) // False
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(-4, 4)) == true) // False
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(3, 4)) == true) // False
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(Point(-4, 4), Point(3, 4), Point(0, -1), Point(0, -1)) == true) // False
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return (0);
}