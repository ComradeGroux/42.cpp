/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:04:11 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:11:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal's constructor called" << std::endl;
	type = "Default";
	return ;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Copy Animal's constructor called" << std::endl;
	type = src.type;
	return ;
}

Animal&	Animal::operator=(const Animal& src)
{
	std::cout << "Assignement Animal's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Default Animal's destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Default Animal's sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return type;
}
