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
    Point(float const x, float const y);
    Point(const Point& copy);
    Point& operator=(const Point& src);
    ~Point(void);
    Fixed getX(void) const;
    Fixed getY(void) const;
    float area_calc(Point const a, Point const b, Point const c) const;

private :
    Fixed const m_x;
    Fixed const m_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif