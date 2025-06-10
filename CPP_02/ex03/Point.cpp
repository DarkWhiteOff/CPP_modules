#include "Point.hpp"

Point::Point(void) : m_x(Fixed()), m_y(Fixed())
{
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : m_x(Fixed(x)), m_y(Fixed(y))
{
    //std::cout << "Surcharged constructor called" << std::endl;
}

Point::Point(const Point& copy)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Point& Point::operator=(const Point& src)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        // m_x = src.getX();
        // m_y = src.getY();
    }
    return (*this);
}

Point::~Point(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX(void) const
{
    return (m_x);
}

Fixed Point::getY(void) const
{
    return (m_y);
}

float Point::area_calc(Point const a, Point const b, Point const c) const
{
    float res = (b.getX().toFloat() - a.getX().toFloat())*(c.getY().toFloat() - a.getY().toFloat())
        - (c.getX().toFloat() - a.getX().toFloat())*(b.getY().toFloat() - a.getY().toFloat());
    if (res < 0)
        res *= -1;
    return (res);
}