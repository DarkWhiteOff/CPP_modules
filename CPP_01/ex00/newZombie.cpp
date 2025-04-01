#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *zomb1 = new Zombie(name);
    return (zomb1);
}