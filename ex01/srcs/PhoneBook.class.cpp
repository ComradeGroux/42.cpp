/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:50:51 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/03 12:02:18 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string PhoneBook::_addStr(std::string str) const
{
	std::string	s;

	std::cout << str << ": ";
	std::getline(std::cin, s);
	while (s.empty())
	{
		std::cout << "This can't be empty." << std::endl;
		std::cout << str << ": ";
		std::getline(std::cin, s);
	}
	return (s);
}

std::string	PhoneBook::_addPhone(std::string str) const
{
	str = _removeWhitespace(str);
	if (_isPhoneNumberValid(str) == false)
	{
		std::cout << "Your phone number's format isn't valid." << std::endl;
		return (_addPhone(_addStr("Please enter a valid number")));
	}
	return (str);
}

bool	PhoneBook::_isPhoneNumberValid(std::string str) const
{
	// Regex a partir de C++11 ou avec utilisation de Boost.
	// std::regex	pReg("\\+?\\d{1,4}?\\(?\\d{1,3}?\\)?\\d{1,4}\\d{1,4}\\d{1,9}");
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			if (i == 0 && str[i] == '+')
				;
			else
				return (false);
		}
	}
	return (true);
}

std::string	PhoneBook::_removeWhitespace(std::string str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]))
			str.erase(i--, 1);
	}
	return (str);
}

void	PhoneBook::addContact(void)
{
	std::string	firstname = _addStr("Firstname");
	std::string	lastname = _addStr("Lastname");
	std::string	nickname = _addStr("Nickname");
	std::string	phone = _addPhone(_addStr("Phone"));
	std::string secret = _addStr("Darkest secret");
	Contact new_Contact(firstname, lastname, nickname,
			phone, secret);
	int		nbContact;

	nbContact = numberContacts();
	if (nbContact < 8)
		this->_contacts[nbContact] = new_Contact;
	else
	{
		Contact newTab[8];
		nbContact--;
		for (int i = nbContact - 1; i >= 0; i--)
			newTab[i] = this->_contacts[i + 1];
		newTab[7] = new_Contact;
		for (int i = 0; i <= nbContact; i++)
			this->_contacts[i] = newTab[i];
	}
}

int	PhoneBook::numberContacts(void) const
{
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].isNull())
			return (i);
	}
	return (8);
}

void PhoneBook::displayTable(void) const
{
	int	select;

	if (this->_contacts[0].isNull())
		std::cout << "Your PhoneBook is empty !" << std::endl;
	else
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			if (this->_contacts[i].isNull())
				break ;
			std::cout << "|" << std::setw(10) << std::setfill(' ') << i;
			_printFormated(this->_contacts[i].getFirstname());
			_printFormated(this->_contacts[i].getLastname());
			_printFormated(this->_contacts[i].getNickname());
			std::cout << std::endl << "|-------------------------------------------|" << std::endl << std::endl;
		}
		std::cout << "Select an index to display more information (-1 to exit this menu): ";
		while (true)
		{
			while (!(std::cin >> select))
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Please, enter a number: ";
			}
			if (select == -1)
				break;
			else if (select < 0 || select >= numberContacts())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "You should select a valid index: ";
			}
			else if (this->_contacts[select].isNull() == false)
				break;
		}
		if (select != -1)
			this->_contacts[select].printFull();
	}
}

void	PhoneBook::_printFormated(std::string value) const
{
	// std::cout << "|" << std::setw(10) << i << "|";
	// std::cout.width(10);
	// std::cout.fill(' ');
	// std::cout << this->_contacts[i].getFirstname() << "|";
	// std::cout << std::setw(10) << this->_contacts[i].getLastname() << "|";
	// std::cout << std::setw(10) << this->_contacts[i].getNickname() << "|" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << std::setfill(' ');
	if (value.length() > 10)
		std::cout << value.substr(0, 9).append(".");
	else
		std::cout << value;
}
