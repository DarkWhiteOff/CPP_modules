#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    Animal *array[10];
    array[10] = NULL;
    int i(0);
    while (i++ < 5)
        array[i] = new Dog();
    i--;
    while (i++ < 10)
        array[i] = new Cat();
    i = 0;
    while (i++ < 10)
        array[i]->makeSound();
    i = 11;
    while (i-- > 0)
        delete array[i];
    return (0);
}