#include "Point.hpp"

float area_calc(Point const a, Point const b, Point const c)
{
    float res = (b.getX().toFloat() - a.getX().toFloat())*(c.getY().toFloat() - a.getY().toFloat())
        - (c.getX().toFloat() - a.getX().toFloat())*(b.getY().toFloat() - a.getY().toFloat());
    if (res < 0)
        res *= -1;
    res = res / 2;
    return (res);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float Atotal = area_calc(a, b, c);
    float A1 = area_calc(a, b, point);
    float A2 = area_calc(b, c, point);
    float A3 = area_calc(c, a, point);

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return (false);
    if (A1 + A2 + A3 == Atotal)
        return (true);
    else
        return (false);
}





// std::cout << "ax : " << a.getX().toFloat() << std::endl;
// std::cout << "ay : " << a.getY().toFloat() << std::endl;
// std::cout << "bx : " << b.getX().toFloat() << std::endl;
// std::cout << "by : " << b.getY().toFloat() << std::endl;
// std::cout << "cx : " << c.getX().toFloat() << std::endl;
// std::cout << "cy : " << c.getY().toFloat() << std::endl;
// std::cout << "px : " << point.getX().toFloat() << std::endl;
// std::cout << "py : " << point.getY().toFloat() << std::endl;
// std::cout << std::endl;
// std::cout << "Atotal : " << Atotal << std::endl;
// std::cout << "A1 : " << A1 << std::endl;
// std::cout << "A2 : " << A2 << std::endl;
// std::cout << "A3 : " << A3 << std::endl;