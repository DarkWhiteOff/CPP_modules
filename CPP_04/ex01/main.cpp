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
    int i = 0;
    while (i <= 4)
        array[i++] = new Dog();
    while (i <= 9)
        array[i++] = new Cat();
    i = 0;
    while (i <= 9)
        array[i++]->makeSound();
    i = 9;
    while (i >= 0)
        delete array[i--];
    return (0);
}