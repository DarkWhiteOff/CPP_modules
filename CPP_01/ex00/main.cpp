#include "Zombie.hpp"

int main(void)
{
    Zombie *zomb1 = newZombie("pedro");
    zomb1->announce();
    randomChump("roberto");
    delete(zomb1);
    return (0);
}