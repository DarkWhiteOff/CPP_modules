#include "PhoneBook.hpp"
// CONSTRUCTOR
PhoneBook::PhoneBook() : m_contacts()
{
	return ;
}
//DESTRUCTOR
PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::addContact(int contact_nb)
{
	std::string tmp_first_n, tmp_last_n, tmp_nickname, tmp_phone_nb, tmp_secret;

	std::cout << "First name : ";
	while (tmp_first_n.empty())
		std::cin >> tmp_first_n;
	m_contacts[contact_nb].setFirstN(tmp_first_n);
	std::cout << std::endl << "Last name : ";
	while (tmp_last_n.empty())
		std::cin >> tmp_last_n;
	m_contacts[contact_nb].setLastN(tmp_last_n);
	std::cout << std::endl << "Nickname : ";
	while (tmp_nickname.empty())
		std::cin >> tmp_nickname;
	m_contacts[contact_nb].setNickname(tmp_nickname);
	std::cout << std::endl << "Phone number : ";
	while (tmp_phone_nb.empty())
		std::cin >> tmp_phone_nb;
	m_contacts[contact_nb].setPhoneNb(tmp_phone_nb);
	std::cout << std::endl << "Darkest secret : ";
	while (tmp_secret.empty())
		std::cin >> tmp_secret;
	m_contacts[contact_nb].setSecret(tmp_secret);
	std::cout << std::endl;
}

void	PhoneBook::search()
{
	int	i(0);

	std::cout << "     INDEX|";
	std::cout << "FIRST NAME|";
	std::cout << " LAST NAME|";
	std::cout << "  NICKNAME|" << std::endl;
	while (m_contacts[i].exists())
	{
		std::cout << "         " << i << "|";
		m_contacts[i].printFirstN();
		std::cout << "|";
		m_contacts[i].printLastN();
		std::cout << "|";
		m_contacts[i].printNickname();
		std::cout << "|" << std::endl;
		i++;
	}
	i = -1;
	std::cout << "Which contact would you like to see ?" << std::endl << "--> ";
	while (!(i >= 0 && i <= 7))
		std::cin >> i;
	std::cout << "Contact " << i << " :" << std::endl;
	m_contacts[i].displayInfos();
}