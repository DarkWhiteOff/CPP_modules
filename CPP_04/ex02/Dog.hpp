#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public :
    Dog(void);
    Dog(const Dog &copy);
    Dog &operator=(const Dog &src);
    ~Dog(void);
    void makeSound(void) const;

    void setIdea(size_t i, std::string idea);
	void getIdeas(void);

private :
    Brain *m_brain;
};

#endif