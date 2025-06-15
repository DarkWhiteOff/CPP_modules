#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public :
    WrongCat(void);
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &src);
    ~WrongCat(void);
    void makeSound(void) const;
};

#endif