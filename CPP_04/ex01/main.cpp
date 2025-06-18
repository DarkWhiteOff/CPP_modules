#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
// SUBJECT TEST DEMONSTRATION
	std::cout << "Test 1 " << std::endl;
	Animal *array[10];
    array[10] = NULL;
    int i = 0;
    while (i <= 4)
        array[i++] = new Dog();
    while (i <= 9)
        array[i++] = new Cat();
    i = 0;
    while (i <= 9)
	{
		std::cout << "Type : " << array[i]->getType() << " | Sound : ";
        array[i++]->makeSound();
	}
    i = 9;
    while (i >= 0)
        delete array[i--];

// DEEP COPY
	std::cout << std::endl;
	std::cout << "Test 2 " << std::endl;
	Dog *walter = new Dog();
	walter->setIdea(0, "Say my name.");
	walter->setIdea(1, "YEAA BITCH, MAGNETSS.");
	walter->setIdea(2, "I did it for me.");
	walter->setIdea(101, "I am the danger.");
	walter->setIdea(-1, "Mr.White");

	Dog *jesse = new Dog(*walter);
	std::cout << std::endl;
	std::cout << "Dog walter ideas: " << std::endl;
	walter->getIdeas();
	delete(walter);
	std::cout << std::endl;

	std::cout << "Dog jesse ideas: " << std::endl;
	jesse->getIdeas();
	delete(jesse);
	std::cout << std::endl;
	return (0);
}