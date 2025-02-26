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
    Fixed& operator=(const Fixed& copy);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

private :
    int                 m_nbVirguleFixe;
    static int const    m_bitNb;
};

#endif