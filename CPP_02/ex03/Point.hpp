#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

class   Point
{
public :
    Point(void);
    Point(const float x, const float y);
    Point(const Point& copy);
    Point& operator=(const Point& src);
    ~Point(void);
    static float area_calc(Point const a, Point const b, Point const c);
    Fixed getX(void) const;
	Fixed getY(void) const;

private :
    const Fixed m_x;
    const Fixed m_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif