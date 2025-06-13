#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class   Fixed
{
public :
    Fixed(void);
    Fixed(const int in);
    Fixed(const float f);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &src);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    bool operator>(const Fixed &X) const;
    bool operator<(const Fixed &X) const;
    bool operator>=(const Fixed &X) const;
    bool operator<=(const Fixed &X) const;
    bool operator==(const Fixed &X) const;
    bool operator!=(const Fixed &X) const;

    Fixed operator+(const Fixed &X) const;
    Fixed operator-(const Fixed &X) const;
    Fixed operator*(const Fixed &X) const;
    Fixed operator/(const Fixed &X) const;

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed &min(Fixed &A, Fixed &B);
    static const Fixed &min(const Fixed &A, const Fixed &B);
    static Fixed &max(Fixed &A, Fixed &B);
    static const Fixed &max(const Fixed &A, const Fixed &B);

private :
    int                 m_nbVirguleFixe;
    static int const    m_bitNb = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif