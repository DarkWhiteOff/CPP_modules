#include "Fixed.hpp"

static int const m_bitNb = 8;

Fixed::Fixed(void) : m_nbVirguleFixe(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : m_nbVirguleFixe(copy.m_nbVirguleFixe)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const nbVirguleFixe) : m_nbVirguleFixe(nbVirguleFixe)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nbVirguleFixe) : m_nbVirguleFixe((int)nbVirguleFixe)
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    m_nbVirguleFixe = copy.m_nbVirguleFixe;
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

    return ();
}
int     Fixed::toInt(void) const
{

    return ();
}