#include "Fixed.hpp"

static int const m_bitNb = 0;

Fixed::Fixed(void) : m_nbnbVirguleFixe(0)
{
    std::cout << "Default consttrucor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : m_nbnbVirguleFixe(copy.m_nbnbVirguleFixe)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    m_nbnbVirguleFixe = copy.m_nbnbVirguleFixe;
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (m_nbnbVirguleFixe);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    m_nbnbVirguleFixe = raw;
}