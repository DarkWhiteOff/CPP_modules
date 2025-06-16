#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    Fixed c(10.47f);
    std::cout << "c : " << c << std::endl;

    Fixed d = ++c;
    std::cout << "d : " << d << std::endl;
    c--;

    Fixed i = c++;
    std::cout << "i : " << i << std::endl;

    ++c;
    std::cout << "c : " << c << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "min : " << Fixed::min(c, d) << std::endl;
    std::cout << "max : " << Fixed::max(c, d) << std::endl;

    Fixed e(16.16f);
    Fixed f = e++;

    std::cout << "e : " << e << std::endl;
    std::cout << "f : " << f << std::endl;

    Fixed g(17);
    Fixed h(Fixed(2.2f) + Fixed(13.5f));

    std::cout << "g : " << g << std::endl;
    std::cout << "h : " << h << std::endl;
    std::cout << "h / 2 : " << h / 2 << std::endl;
    std::cout << "h * 2 : " << h * 2 << std::endl;
    std::cout << "g + 8 : " << g + 8 << std::endl;
    std::cout << "g - 4 : " << g - 4 << std::endl;

    Fixed test(17);
    std::cout << g.operator!=(h) << std::endl;
    std::cout << g.operator==(test) << std::endl;
    std::cout << g.operator>=(h) << std::endl;
    std::cout << g.operator<=(h) << std::endl;
    std::cout << g.operator<=(h/2) << std::endl;
    std::cout << g.operator>=(h/2) << std::endl;

    return (0);
}