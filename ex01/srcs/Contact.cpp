/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:25:10 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 20:51:42 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, int phone, std::string secret)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phone = phone;
	this->secret = secret;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::getFirstname(void)
{
	return this->firstname;
}

std::string Contact::getLastname(void)
{
	return this->lastname;
}

std::string Contact::getNickname(void)
{
	return this->nickname;
}

int Contact::getPhone(void)
{
	return this->phone;
}

std::string Contact::getSecret(void)
{
	return this->secret;
}

void Contact::printInfo(void)
{
	
}

void Contact::printFull(void)
{
	std::cout << "First name:     " << this->firstname << std::endl;
	std::cout << "Last name:      " << this->lastname << std::endl;
	std::cout << "Nick name:      " << this->nickname << std::endl;
	std::cout << "Phone number:   " << this->phone << std::endl;
	std::cout << "Darkest secret: " << this->secret << std::endl;
}

bool Contact::isNull(void)
{
	if (this->firstname.empty())
		return (true);
	else
		return (false);
}
