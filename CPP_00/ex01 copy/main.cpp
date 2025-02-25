#include "PhoneBook.hpp"

int main()
{
    PhoneBook goat;
    std::string input;
    int i(0);

    std::cout << "> ";
    std::cin >> input;
    while (input != "EXIT")
    {
        if (input == "ADD")
        {
            goat.addContact(i);
            i++;
        }
        if (input == "SEARCH")
            goat.search();
        std::cout << std::endl << "> ";
        std::cin >> input;
    }
    return (0);
}