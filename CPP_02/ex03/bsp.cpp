#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float A1;
    float A2;
    float A3;

    A1 = (b.getX().toFloat() - a.getX().toFloat())*(point.getY().toFloat() - a.getY().toFloat())
        - (point.getX().toFloat() - a.getX().toFloat())*(b.getY().toFloat() - a.getY().toFloat()); // a b point
    A2 = (b.getX().toFloat() - point.getX().toFloat())*(c.getY().toFloat() - point.getY().toFloat())
        - (c.getX().toFloat() - point.getX().toFloat())*(b.getY().toFloat() - point.getY().toFloat()); // b c point
    A3 = (point.getX().toFloat() - a.getX().toFloat())*(c.getY().toFloat() - a.getY().toFloat())
        - (c.getX().toFloat() - a.getX().toFloat())*(point.getY().toFloat() - a.getY().toFloat()); // c a point
    if (A1 < 0)
        A1 *= -1;
    if (A2 < 0)
        A2 *= -1;
    if (A3 < 0)
        A3 *= -1;
    #include <stdio.h>
    printf("Area : %f\n", a.area_calc(a, b, c));
    printf("A1 : %f, A2 : %f, A3 : %f\n", A1, A2, A3);
    if (A1 + A2 + A3 == a.area_calc(a, b, c))
        return (true);
    else
        return (false);
}