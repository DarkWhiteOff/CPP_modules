#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class   Zombie
{
public :
    Zombie(void);
    Zombie(std::string n);
    ~Zombie(void);
    void    announce(void);
    void    giveName(std::string name);

private :
    std::string m_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif