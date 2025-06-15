#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
public :
    Dog(void);
    Dog(const Dog &copy);
    Dog &operator=(const Dog &src);
    ~Dog(void);
    void makeSound(void) const;
};

#endif