/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:50:51 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/30 13:18:37 by vgroux           ###   ########.fr       */
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
	std::cin >> s;
	return (s);
}

std::string	PhoneBook::_addPhone(std::string str) const
{
	if (_isPhoneNumberValid(str) == false)
	{
		std::cout << "Your phone number's format isn't valid." << std::endl;
		return (_addPhone(_addStr("Please enter a valid number")));
	}
	return (str);
}

bool	PhoneBook::_isPhoneNumberValid(std::string str) const
{
	regex_t phone_regex;

	int ret = regcomp(&phone_regex, "^\\+?[0-9]{1,3}[\\-\\s]?\\([0-9]{3}\\)[\\-\\s]?[0-9]{3}[\\-\\s]?[0-9]{4}$", REG_EXTENDED);
	if (ret != 0) {
		regfree(&phone_regex);
		return false;
	}

	ret = regexec(&phone_regex, str.c_str(), 0, NULL, 0);
	regfree(&phone_regex);

	return (ret == 0);
}

void	PhoneBook::addContact(void)
{
	Contact new_Contact(_addStr("Firstname"), _addStr("Lastname"),
						_addStr("Nickname"), _addPhone(_addStr("Phone")),
						_addStr("Darkest secret"));
	int		i;

	i = numberContact();
	// Verifier si on atteins le max 
	// Ajouter en consequence
}

int	PhoneBook::numberContact(void) const
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
			std::cout << "|" << std::setw(10) << i << "|";
			std::cout << std::setw(10) << this->_contacts[i].getFirstname() << "|";
			std::cout << std::setw(10) << this->_contacts[i].getLastname() << "|";
			std::cout << std::setw(10) << this->_contacts[i].getNickname() << "|" << std::endl;
		}
		std::cout << "|-------------------------------------------|" << std::endl;
		while (true)
		{
			std::cout << "Select an index to display more information: " << std::endl;
			while (!(std::cin >> select))
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Please, enter a number: ";
			}
			if (this->_contacts[select].isNull() == false)
				break ;
		}
		this->_contacts[select].printFull();
	}
}
