/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:25:10 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/30 13:18:43 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phone, std::string secret)
	: _firstname(firstname), _lastname(lastname), _nickname(nickname), _phone(phone), _secret(secret)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getFirstname(void) const
{
	return this->_firstname;
}

std::string Contact::getLastname(void) const
{
	return this->_lastname;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhone(void) const
{
	return this->_phone;
}

std::string Contact::getSecret(void) const
{
	return this->_secret;
}

void Contact::printFull(void) const
{
	std::cout << "First name:     " << this->_firstname << std::endl;
	std::cout << "Last name:      " << this->_lastname << std::endl;
	std::cout << "Nick name:      " << this->_nickname << std::endl;
	std::cout << "Phone number:   " << this->_phone << std::endl;
	std::cout << "Darkest secret: " << this->_secret << std::endl;
}

bool Contact::isNull(void) const
{
	if (this->_firstname.empty())
		return (true);
	else
		return (false);
}
