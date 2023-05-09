/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:34:04 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:34:16 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default WrongAnimal's constructor called" << std::endl;
	type = "Default";
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "Copy WrongAnimal's constructor called" << std::endl;
	type = src.type;
	return ;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "Assignement WrongAnimal's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Default WrongAnimal's destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Default WrongAnimal's sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return type;
}
