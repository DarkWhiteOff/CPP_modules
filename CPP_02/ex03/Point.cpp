#include "Point.hpp"

Point::Point(void) : m_x(0), m_y(0)
{
    // std::cout << "Default constructor called P" << std::endl;
}

Point::Point(const float x, const float y) : m_x(x), m_y(y)
{
    // std::cout << "Surcharged constructor called P" << std::endl;
}

Point::Point(const Point &copy) : m_x(copy.m_x), m_y(copy.m_y)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &src)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        (Fixed)m_x = src.m_x;
        (Fixed)m_y = src.m_y;
    }
    return (*this);
}

Point::~Point(void)
{
    //std::cout << "Destructor called" << std::endl;
}

const Fixed Point::getX(void) const
{
	return (m_x);
}
const Fixed Point::getY(void) const
{
	return (m_y);
}