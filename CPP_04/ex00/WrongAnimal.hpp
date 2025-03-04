#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public :
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal& operator=(const WrongAnimal& src);
    virtual ~WrongAnimal(void);
    std::string     getType(void) const;
    void    makeSound(void) const;

protected :
    std::string m_type;
};

#endif