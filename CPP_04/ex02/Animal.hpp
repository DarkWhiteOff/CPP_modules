#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public :
    Animal(void);
    Animal(const Animal& copy);
    Animal& operator=(const Animal& src);
    virtual ~Animal(void);
    std::string     getType(void) const;
    virtual void    makeSound(void) const;

protected :
    std::string m_type;
};

#endif