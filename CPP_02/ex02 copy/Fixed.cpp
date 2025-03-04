#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : m_nbVirguleFixe(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : m_nbVirguleFixe(copy.m_nbVirguleFixe)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const nbVirguleFixe) : m_nbVirguleFixe(nbVirguleFixe << m_bitNb)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nbVirguleFixe) : m_nbVirguleFixe(roundf(nbVirguleFixe * (1 << m_bitNb)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    m_nbVirguleFixe = src.m_nbVirguleFixe;
    return (*this);
}

Fixed& Fixed::operator+=(const Fixed& src)
{
    m_nbVirguleFixe += src.m_nbVirguleFixe;
    return (*this);
}

Fixed& Fixed::operator-=(const Fixed& src)
{
    m_nbVirguleFixe -= src.m_nbVirguleFixe;
    return (*this);
}

Fixed& Fixed::operator*=(const Fixed& src)
{
    m_nbVirguleFixe *= src.m_nbVirguleFixe;
    return (*this);
}

Fixed& Fixed::operator/=(const Fixed& src)
{
    m_nbVirguleFixe /= src.m_nbVirguleFixe;
    return (*this);
}

Fixed	Fixed::operator++(int)
{
    Fixed copy(*this);
    m_nbVirguleFixe += 1;
    return (copy);
}

Fixed&	Fixed::operator++(void)
{
    m_nbVirguleFixe += 1;
    return (*this);
}

Fixed	Fixed::operator--(int)
{
    Fixed copy(*this);
    m_nbVirguleFixe -= 1;
    return (copy);
}

Fixed&	Fixed::operator--(void)
{
    m_nbVirguleFixe -= 1;
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
    return ((float)m_nbVirguleFixe / (1 << m_bitNb));
}
int     Fixed::toInt(void) const
{
    return (m_nbVirguleFixe >> m_bitNb);
}

Fixed& Fixed::min(Fixed& A, Fixed& B)
{
    if (A.getRawBits() < B.getRawBits())
        return (A);
    else
        return (B);
}

const Fixed& Fixed::min(const Fixed& A, const Fixed& B)
{
    if (A.getRawBits() < B.getRawBits())
        return (A);
    else
        return (B);
}

Fixed& Fixed::max(Fixed& A, Fixed& B)
{
    if (A.getRawBits() > B.getRawBits())
        return (A);
    else
        return (B);
}

const Fixed& Fixed::max(const Fixed& A, const Fixed& B)
{
    if (A.getRawBits() > B.getRawBits())
        return (A);
    else
        return (B);
}

// COMAPRISON OPERATORS
bool operator>(const Fixed& A, const Fixed& B)
{
    return (A.getRawBits() > B.getRawBits());
}

bool operator<(const Fixed& A, const Fixed& B)
{
    return (A.getRawBits() < B.getRawBits());
}

bool operator>=(const Fixed& A, const Fixed& B)
{
    return (A.getRawBits() >= B.getRawBits());
}

bool operator<=(const Fixed& A, const Fixed& B)
{
    return (A.getRawBits() <= B.getRawBits());
}

bool operator==(const Fixed& A, const Fixed& B)
{
    return (A.getRawBits() == B.getRawBits());
}

bool operator!=(const Fixed& A, const Fixed& B)
{
    return (A.getRawBits() != B.getRawBits());
}

// ARITHMETIC OPERATORS
Fixed operator+(const Fixed& A, const Fixed& B)
{
    Fixed copyA(A);
    copyA += B;
    return (copyA);
}

Fixed operator-(const Fixed& A, const Fixed& B)
{
    Fixed copyA(A);
    copyA -= B;
    return (copyA);
}

Fixed operator*(const Fixed& A, const Fixed& B)
{
    Fixed copyA(A);
    copyA *= B;
    return (copyA);
}

Fixed operator/(const Fixed& A, const Fixed& B)
{
    Fixed copyA(A);
    copyA /= B;
    return (copyA);
}

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	os << number.toFloat();
	return ( os );
}