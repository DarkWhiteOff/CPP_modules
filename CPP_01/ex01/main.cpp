#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    Zombie *horde1 = zombieHorde(5, "pedro");
    int i(0);
    while (i < 5)
    {
        horde1[i].announce();
        i++;
    }
    delete[]horde1;
    return (0);
}