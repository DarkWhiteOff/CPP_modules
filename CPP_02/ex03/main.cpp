#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a(2, -2);
    Point b(3, 4);
    Point c(-4, 2);
    Point point(16, -16);

    if (bsp(a, b, c, point) == true)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return 0;
}