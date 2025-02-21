#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public :

    void addContact(contact[int nb]);
    void search();

    private :

    std::Contact  contact[8];
};

#endif