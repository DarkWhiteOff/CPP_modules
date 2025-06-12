#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    if (bsp(Point(2, -2), Point(3, 4), Point(-4, 2), Point(1, 1)) == true)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return (0);
}