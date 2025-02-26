#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class   Fixed
{
public :
    Fixed(void);
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

private :
    int                 m_nbnbVirguleFixe;
    static int const    m_bitNb;
};

#endif