#include "Fixed.hpp"

Fixed::Fixed(void) : m_nbVirguleFixe(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int in)
{
    std::cout << "Int constructor called" << std::endl;
    int nbVirguleFixe = in;
    int i = 8;
    while (i > 0)
    {
        nbVirguleFixe *= 2;
        i--;
    }
    m_nbVirguleFixe = nbVirguleFixe;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    float nbVirguleFixe = f;
    int i = 8;
    while (i > 0)
    {
        nbVirguleFixe *= 2;
        i--;
    }
    m_nbVirguleFixe = roundf(nbVirguleFixe);
}

Fixed::Fixed(const Fixed &copy)// : m_nbVirguleFixe(copy.m_nbVirguleFixe)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        m_nbVirguleFixe = src.m_nbVirguleFixe;
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (m_nbVirguleFixe);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    m_nbVirguleFixe = raw;
}

float   Fixed::toFloat(void) const
{
    float nbVirguleFixe = m_nbVirguleFixe;
    int i = 8;
    while (i > 0)
    {
        nbVirguleFixe /= 2;
        i--;
    } 
    return (nbVirguleFixe);
}

int     Fixed::toInt(void) const
{
    int nbVirguleFixe = m_nbVirguleFixe;
    int i = 8;
    while (i > 0)
    {
        nbVirguleFixe /= 2;
        i--;
    } 
    return (nbVirguleFixe);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}