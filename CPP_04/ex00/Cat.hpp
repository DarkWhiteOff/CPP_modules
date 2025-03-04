#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public :
    Cat(void);
    Cat(const Cat& copy);
    Cat& operator=(const Cat& src);
    virtual ~Cat(void);
    virtual void makeSound(void) const;
};

#endif