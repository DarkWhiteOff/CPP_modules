#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point const a(-5, 6);
    Point const b(2, 4);
    Point const c(1, -4);

    Point const pointD(-2, 3);
    Point const pointE(-1.5, 5.8);
    Point const pointF(-3.3, 3.1);
    Point const pointG(1.4, -1.1);
    Point const pointH(0.6, -3.7);

    //TEST TRUE
    if (bsp(a, b, c, pointD) == true) // True
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    //TESTS FALSE
    if (bsp(a, b, c, pointE) == true) // False (Out)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(a, b, c, pointF) == true) // False (Arrete)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(a, b, c, pointG) == true) // False (Arrete)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(a, b, c, pointH) == true) // False (Out)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    if (bsp(a, b, c, a) == true) // False (Sommet)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(a, b, c, b) == true) // False (Sommet)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    if (bsp(a, b, c, c) == true) // False (Sommet)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return (0);
}