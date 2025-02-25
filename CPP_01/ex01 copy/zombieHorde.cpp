#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i(0);
    Zombie *horde;

    while (i < N)
    {
        horde[i] = new Zombie(name);
        i++;
    }
    return (horde);
}