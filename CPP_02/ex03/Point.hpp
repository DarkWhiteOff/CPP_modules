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
    const float getX(void) const;
	const float getY(void) const;

private :
    const Fixed m_x;
    const Fixed m_y;
};

float area_calc(const float ax, const float ay, const float bx, const float by, const float cx, const float cy);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif