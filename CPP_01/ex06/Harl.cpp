#include "Harl.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void    Harl::debug(void)
{
    std::cout << "[DEBUG] I love having extra bacon..." << std::endl;
}
void    Harl::info(void)
{
    std::cout << "[INFO] I coannot believe adding extra bacon cost more money..." << std::endl;
}
void    Harl::warning(void)
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free..." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR] This is unacceptable..." << std::endl;
}

void    Harl::complain(std::string level)
{
    void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i(-1);

    while (levels[i++ - 1] != "ERROR")
    {
        if (levels[i] == level)
        {
            while (levels[i - 1] != "ERROR")
            {
                (this->*function[i])();
                i++;
            }
        }
    }
}