#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    //exit(0);
    float Atotal;
    float A1;
    float A2;
    float A3;

    std::cout << a.getX() << std::endl;
    std::cout << a.getY() << std::endl;
    std::cout << b.getX() << std::endl;
    std::cout << b.getY() << std::endl;
    std::cout << c.getX() << std::endl;
    std::cout << c.getY() << std::endl;
    std::cout << point.getX() << std::endl;
    std::cout << point.getY() << std::endl;
    Atotal = Point::area_calc(a, b, c);
    A1 = Point::area_calc(a, b, point);
    A2 = Point::area_calc(b, c, point);
    A3 = Point::area_calc(c, a, point);
    std::cout << A1 << std::endl;
    std::cout << A2 << std::endl;
    std::cout << A3 << std::endl;
    // if (A1 + A2 + A3 == Point::area_calc(a, b, c))
    //     return (true);
    // else
    //     return (false);
    return (true);
}