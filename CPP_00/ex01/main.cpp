#include "PhoneBook.hpp"

int main()
{
    PhoneBook goat;
    std::string input;
    int i(0);

    std::cout << "> ";
    std::getline(std::cin, input);
    while (input != "EXIT")
    {
        if (input == "ADD")
        {
            goat.addContact(i);
            i++;
            if (i == 8)
                i = 0;
        }
        if (input == "SEARCH")
            goat.search();
        if (std::cin.eof())
            return (0);
        std::cout << "> ";
        std::getline(std::cin, input);
    }
    return (0);
}