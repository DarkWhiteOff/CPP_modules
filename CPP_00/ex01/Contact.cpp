#include "Contact.hpp"

// CONSTRUCTOR
Contact::Contact() : m_first_n(), m_last_n(), m_nickname(), m_phone_nb(), m_secret()
{
    return ;
}
//DESTRUCTOR
Contact::~Contact()
{
    return ;
}

// SET
void    Contact::setFirstN(std::string str)
{
    m_first_n = str;
}

void    Contact::setLastN(std::string str)
{
    m_last_n = str;
}

void    Contact::setNickname(std::string str)
{
    m_nickname = str;
}

void    Contact::setPhoneNb(std::string str)
{
    m_phone_nb = str;
}

void    Contact::setSecret(std::string str)
{
    m_secret = str;
}

// PRINT
void    Contact::printFirstN()
{
    if (m_first_n.size() > 10)
    {
        std::string newstr(m_first_n.substr(0, 9));
        newstr.append(".");
        std::cout << newstr;
    }
    else if (m_first_n.size() <= 10)
    {
        int nb_spaces(10 - m_first_n.size());
        std::string newstr(m_first_n);
        while (nb_spaces--)
            newstr.insert(0, " ");
        std::cout << newstr;
    }
}

void    Contact::printLastN()
{
    if (m_last_n.size() > 10)
    {
        std::string newstr(m_last_n.substr(0, 9));
        newstr.append(".");
        std::cout << newstr;
    }
    else if (m_last_n.size() <= 10)
    {
        int nb_spaces(10 - m_last_n.size());
        std::string newstr(m_last_n);
        while (nb_spaces--)
            newstr.insert(0, " ");
        std::cout << newstr;
    }
}

void    Contact::printNickname()
{
    if (m_nickname.size() > 10)
    {
        std::string newstr(m_nickname.substr(0, 9));
        newstr.append(".");
        std::cout << newstr;
    }
    else if (m_nickname.size() <= 10)
    {
        int nb_spaces(10 - m_nickname.size());
        std::string newstr(m_nickname);
        while (nb_spaces--)
            newstr.insert(0, " ");
        std::cout << newstr;
    }
}

void    Contact::printPhoneNb()
{
    std::cout << m_phone_nb;
}

void    Contact::printSecret()
{
    std::cout << m_secret;
}

bool    Contact::exists()
{
    if (m_first_n.size() > 0)
        return (true);
    return (false);
}

void    Contact::displayInfos()
{
    std::cout << "First name : " << m_first_n << std::endl;
    std::cout << "Last name : " << m_last_n << std::endl;
    std::cout << "Nickname : " << m_nickname << std::endl;
    std::cout << "Phone number : " << m_phone_nb << std::endl;
    std::cout << "Darkest secret : " << m_secret << std::endl;
}