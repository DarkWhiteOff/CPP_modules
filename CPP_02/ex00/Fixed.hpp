#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class   Fixed
{
public :
    Fixed(void);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &src);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

private :
    int                 m_nbVirguleFixe;
    static int const    m_bitNb = 8;
};

#endif