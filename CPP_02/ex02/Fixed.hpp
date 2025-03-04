#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class   Fixed
{
public :
    Fixed(void);
    Fixed(const Fixed& copy);
    Fixed(int const nbVirguleFixe);
    Fixed(float const nbVirguleFixe);

    Fixed& operator=(const Fixed& src);

    Fixed& operator+=(const Fixed& src);
    Fixed& operator-=(const Fixed& src);
    Fixed& operator*=(const Fixed& src);
    Fixed& operator/=(const Fixed& src);

    Fixed	operator++(int);
    Fixed&	operator++(void);
    Fixed	operator--(int);
    Fixed&	operator--(void);

    ~Fixed(void);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    static Fixed& min(Fixed& A, Fixed& B);
    static const Fixed& min(const Fixed& A, const Fixed& B);
    static Fixed& max(Fixed& A, Fixed& B);
    static const Fixed& max(const Fixed& A, const Fixed& B);

private :
    int                 m_nbVirguleFixe;
    static int const    m_bitNb = 8;
};

bool operator>(const Fixed& A, const Fixed& B);
bool operator<(const Fixed& A, const Fixed& B);
bool operator>=(const Fixed& A, const Fixed& B);
bool operator<=(const Fixed& A, const Fixed& B);
bool operator==(const Fixed& A, const Fixed& B);
bool operator!=(const Fixed& A, const Fixed& B);

Fixed operator+(const Fixed& A, const Fixed& B);
Fixed operator-(const Fixed& A, const Fixed& B);
Fixed operator*(const Fixed& A, const Fixed& B);
Fixed operator/(const Fixed& A, const Fixed& B);

std::ostream& operator<<( std::ostream& os, const Fixed& number );

#endif