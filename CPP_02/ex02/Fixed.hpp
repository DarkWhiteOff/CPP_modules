#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class   Fixed
{
public :
    Fixed(void);
    Fixed(int const nbVirguleFixe);
    Fixed(float const nbVirguleFixe);
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& src);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    bool operator>(const Fixed& X);
    bool operator<(const Fixed& X);
    bool operator>=(const Fixed& X);
    bool operator<=(const Fixed& X);
    bool operator==(const Fixed& X);
    bool operator!=(const Fixed& X);

    Fixed operator+(const Fixed& X);
    Fixed operator-(const Fixed& X);
    Fixed operator*(const Fixed& X);
    Fixed operator/(const Fixed& X);

    Fixed	operator++(int);
    Fixed&	operator++(void);
    Fixed	operator--(int);
    Fixed&	operator--(void);
    Fixed& operator+=(const Fixed& src);
    Fixed& operator-=(const Fixed& src);
    Fixed& operator*=(const Fixed& src);
    Fixed& operator/=(const Fixed& src);

    static Fixed& min(Fixed& A, Fixed& B);
    static const Fixed& min(const Fixed& A, const Fixed& B);
    static Fixed& max(Fixed& A, Fixed& B);
    static const Fixed& max(const Fixed& A, const Fixed& B);

private :
    int                 m_nbVirguleFixe;
    static int const    m_bitNb = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif