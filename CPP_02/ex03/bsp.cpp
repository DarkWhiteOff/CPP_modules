#include "Point.hpp"

float area_calc(const float ax, const float ay, const float bx, const float by, const float cx, const float cy)
{
    float res = (bx - ax)*(cy - ay) - (cx - ax)*(by - ay);
    if (res < 0)
        res *= -1;
    res = res / 2;
    return (res);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float Atotal;
    float A1;
    float A2;
    float A3;

    Atotal = area_calc(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
    A1 = area_calc(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
    A2 = area_calc(b.getX(), b.getY(), c.getX(), c.getY(), point.getX(), point.getY());
    A3 = area_calc(c.getX(), c.getY(), a.getX(), a.getY(), point.getX(), point.getY());
    if (A1 == 0 || A2 == 0 || A3 == 0)
        return (false);
    if (A1 + A2 + A3 == Atotal)
        return (true);
    else
        return (false);
}





// std::cout << "ax : " << a.getX() << std::endl;
// std::cout << "ay : " << a.getY() << std::endl;
// std::cout << "bx : " << b.getX() << std::endl;
// std::cout << "by : " << b.getY() << std::endl;
// std::cout << "cx : " << c.getX() << std::endl;
// std::cout << "cy : " << c.getY() << std::endl;
// std::cout << "px : " << point.getX() << std::endl;
// std::cout << "py : " << point.getY() << std::endl;
// std::cout << std::endl;
// std::cout << "Atotal : " << Atotal << std::endl;
// std::cout << "A1 : " << A1 << std::endl;
// std::cout << "A2 : " << A2 << std::endl;
// std::cout << "A3 : " << A3 << std::endl;