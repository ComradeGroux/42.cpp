/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:50:51 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/29 15:56:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string PhoneBook::addStr(std::string str) const
{
	std::string	s;

	std::cout << str << ": ";
	std::cin >> s;
	return (s);
}

void	PhoneBook::addContact(void)
{
	Contact new_Contact(addStr("Firstname"), addStr("Lastname"),
						addStr("Nickname"), addStr("Phone"),
						addStr("Darkest secret"));
	int		i;

	i = this->numberContact();
	// Verifier si on atteins le max 
	// Ajouter en consequence
}

int	PhoneBook::numberContact(void) const
{
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].isNull())
			return (i);
	}
	return (8);
}

void PhoneBook::displayTable(void) const
{
	int	select;

	if (this->contacts[0].isNull())
		std::cout << "Your PhoneBook is empty !" << std::endl;
	else
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			if (this->contacts[i].isNull())
				break ;
			std::cout << "|" << std::setw(10) << i << "|";
			std::cout << std::setw(10) << this->contacts[i].getFirstname() << "|";
			std::cout << std::setw(10) << this->contacts[i].getLastname() << "|";
			std::cout << std::setw(10) << this->contacts[i].getNickname() << "|" << std::endl;
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
			if (this->contacts[select].isNull() == false)
				break ;
		}
		this->contacts[select].printFull();
	}
}

