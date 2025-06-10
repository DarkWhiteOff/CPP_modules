#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : m_contacts()
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

int		PhoneBook::onlyNumbers(std::string tmp_phone_nb)
{
	int i(0);

	if (tmp_phone_nb[i] == '\0' || tmp_phone_nb[i] == '\n')
		return (1);
	while (tmp_phone_nb[i] != '\0')
	{
		if (!(tmp_phone_nb[i] >= '0' && tmp_phone_nb[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	PhoneBook::addContact(int contact_nb)
{
	std::string tmp_first_n, tmp_last_n, tmp_nickname, tmp_phone_nb, tmp_secret;

	std::cout << "First name : ";
	std::getline(std::cin, tmp_first_n);
	while (tmp_first_n.empty())
	{
		if (std::cin.eof())
            return ;
		std::cout << "First name : ";
		std::getline(std::cin, tmp_first_n);
	}
	m_contacts[contact_nb].setFirstN(tmp_first_n);

	std::cout << "Last name : ";
	std::getline(std::cin, tmp_last_n);
	while (tmp_last_n.empty())
	{
		if (std::cin.eof())
            return ;
		std::cout << "Last name : ";
		std::getline(std::cin, tmp_last_n);
	}
	m_contacts[contact_nb].setLastN(tmp_last_n);

	std::cout << "Nickname : ";
	std::getline(std::cin, tmp_nickname);
	while (tmp_nickname.empty())
	{
		if (std::cin.eof())
            return ;
		std::cout << "Nickname : ";
		std::getline(std::cin, tmp_nickname);
	}
	m_contacts[contact_nb].setNickname(tmp_nickname);

	std::cout << "Phone number : ";
	std::getline(std::cin, tmp_phone_nb);
	while (tmp_phone_nb.empty() || onlyNumbers(tmp_phone_nb) == 1)
	{
		if (std::cin.eof())
            return ;
		std::cout << "Phone number : ";
		std::getline(std::cin, tmp_phone_nb);
	}
	m_contacts[contact_nb].setPhoneNb(tmp_phone_nb);

	std::cout << "Darkest secret : ";
	std::getline(std::cin, tmp_secret);
	while (tmp_secret.empty())
	{
		if (std::cin.eof())
            return ;
		std::cout << "Darkest secret : ";
		std::getline(std::cin, tmp_secret);
	}
	m_contacts[contact_nb].setSecret(tmp_secret);
}

int PhoneBook::goodIndex(std::string index)
{
	if (index.size() > 1)
		return (0);
	if (index[0] >= '0' && index[0] <= '7')
		return (1);
	return (0);
}

void	PhoneBook::search()
{
	int	i(0);
	std::string index;

	std::cout << "     INDEX|";
	std::cout << "FIRST NAME|";
	std::cout << " LAST NAME|";
	std::cout << "  NICKNAME|" << std::endl;
	while (m_contacts[i].exists() && i < 8)
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
	if (i == 0)
		return ;
	std::cout << "Which contact would you like to see ?" << std::endl << "--> ";
	std::getline(std::cin, index);
	while (goodIndex(index) == 0)
	{
		if (std::cin.eof())
            return ;
		std::cout << "--> ";
		std::getline(std::cin, index);
	}
	std::cout << "Contact " << index << " :" << std::endl;
	std::istringstream is(index);
	is >> i;
	m_contacts[i].displayInfos();
}