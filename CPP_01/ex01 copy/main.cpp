#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    Zombie *zomb1 = zombieHorde(5, "pedro");
    (void)zomb1;
    return (0);
}