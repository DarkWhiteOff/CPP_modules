#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public :
    Cat(void);
    Cat(const Cat &copy);
    Cat &operator=(const Cat &src);
    ~Cat(void);
    void makeSound(void) const;

    void setIdea(size_t i, std::string idea);
	void getIdeas(void);

private :
    Brain *m_brain;
};

#endif