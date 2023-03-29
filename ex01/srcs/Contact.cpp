/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:25:10 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/29 14:18:44 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, int phone, std::string secret)
	: firstname(firstname), lastname(lastname), nickname(nickname), phone(phone), secret(secret)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getFirstname(void) const
{
	return this->firstname;
}

std::string Contact::getLastname(void) const
{
	return this->lastname;
}

std::string Contact::getNickname(void) const
{
	return this->nickname;
}

int Contact::getPhone(void) const
{
	return this->phone;
}

std::string Contact::getSecret(void) const
{
	return this->secret;
}

void Contact::printInfo(void) const
{
	
}

void Contact::printFull(void) const
{
	std::cout << "First name:     " << this->firstname << std::endl;
	std::cout << "Last name:      " << this->lastname << std::endl;
	std::cout << "Nick name:      " << this->nickname << std::endl;
	std::cout << "Phone number:   " << this->phone << std::endl;
	std::cout << "Darkest secret: " << this->secret << std::endl;
}

bool Contact::isNull(void) const
{
	if (this->firstname.empty())
		return (true);
	else
		return (false);
}
