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

    std::cout << std::endl;
    Fixed c(10.47f);
    std::cout << "c begin : " << c << std::endl;

    Fixed d = ++c;
    std::cout << "d with ++c on it : " << d << std::endl;
    c--;

    Fixed i = c++;
    std::cout << "i without ++c on it (because c++) : " << i << std::endl;

    std::cout << std::endl;
    c++;
    std::cout << "c : " << c << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "min : " << Fixed::min(c, d) << " (d)" << std::endl;
    std::cout << "max : " << Fixed::max(c, d) << " (c)" << std::endl;

    std::cout << std::endl;
    Fixed e(16.16f);
    Fixed f = e++;

    std::cout << "e (larger cause e++) : " << e << std::endl;
    std::cout << "f (smaller cause wasn't ++e): " << f << std::endl;

    Fixed g(17);
    Fixed h(Fixed(2.2f) + Fixed(13.5f));

    std::cout << "g : " << g << std::endl;
    std::cout << "h : " << h << std::endl;

    std::cout << std::endl;
    std::cout << "h / 2 : " << h / 2 << std::endl;
    std::cout << "h * 2 : " << h * 2 << std::endl;
    std::cout << "g + 8 : " << g + 8 << std::endl;
    std::cout << "g - 4 : " << g - 4 << std::endl;

    std::cout << std::endl;
    Fixed test(17);
    std::cout << g.operator!=(h) << " (g != h is true) " << g << " != " << h << std::endl;
    std::cout << g.operator==(test) << " (g == test is true) " << g << " == " << test << std::endl;
    std::cout << g.operator>=(h) << " (g >= h is true) " << g << " >= " << h << std::endl;
    std::cout << g.operator<=(h) << " (g <= h is false) " << g << " <= " << h << std::endl;
    std::cout << g.operator<=(h/2) << " (g <= h/2 is false) " << g << " <= " << h / 2 << std::endl;
    std::cout << g.operator>=(h/2) << " (g >= h is true) " << g << " >= " << h / 2 << std::endl;

    return (0);
}