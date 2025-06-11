#include "Point.hpp"

Point::Point(void) : m_x(0), m_y(0)
{
    std::cout << "Default constructor called P" << std::endl;
}

Point::Point(const float x, const float y) : m_x(x), m_y(y)
{
    std::cout << "Surcharged constructor called P" << std::endl;
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
        // m_x = src.m_x;
        // m_y = src.m_y;
    }
    return (*this);
}

Point::~Point(void)
{
    //std::cout << "Destructor called" << std::endl;
}

float Point::area_calc(Point const a, Point const b, Point const c)
{
    std::cout << a.getX() << std::endl;
    std::cout << a.getY() << std::endl;
    std::cout << b.getX() << std::endl;
    std::cout << b.getY() << std::endl;
    std::cout << c.getX() << std::endl;
    std::cout << c.getY() << std::endl;
    exit(0);
    std::cout << a.m_x.toFloat() << std::endl;
    std::cout << a.m_y.toFloat() << std::endl;
    float res = (b.m_x.toFloat() - a.m_x.toFloat())*(c.m_y.toFloat() - a.m_y.toFloat())
        - (c.m_x.toFloat() - a.m_x.toFloat())*(b.m_y.toFloat() - a.m_y.toFloat()) / 2;
    if (res < 0)
        res *= -1;
    return (res);
}

Fixed Point::getX(void) const
{
	return m_x;
}
Fixed Point::getY(void) const
{
	return m_y;
}