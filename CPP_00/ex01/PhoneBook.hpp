#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
public :
    PhoneBook();
    ~PhoneBook();
    void addContact(int contact_nb);
    int onlyNumbers(std::string tmp_phone_nb);
    void search();
    int goodIndex(std::string index);

private :
    Contact  m_contacts[8];
};

#endif