#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
public :
    Contact();
    ~Contact();
    void setFirstN(std::string str);
    void setLastN(std::string str);
    void setNickname(std::string str);
    void setPhoneNb(std::string str);
    void setSecret(std::string str);
    void printFirstN();
    void printLastN();
    void printNickname();
    void printPhoneNb();
    void printSecret();
    bool exists();
    void displayInfos();

private :
    std::string  m_first_n;
    std::string  m_last_n;
    std::string  m_nickname;
    std::string  m_phone_nb;
    std::string  m_secret;
};

#endif