#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public :
    PhoneBook();
    ~PhoneBook();
    void addContact(int contact_nb);
    void search();

private :
    Contact  m_contacts[8];
};

#endif