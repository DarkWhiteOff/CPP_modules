#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    std::cout << bsp(Point(2, -2), Point(3, 4), Point(-4, 2), Point(1, 1)) << std::endl;
    return 0;
}