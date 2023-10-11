/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:04:11 by vgroux            #+#    #+#             */
/*   Updated: 2023/10/11 16:58:11 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Default AAnimal's constructor called" << std::endl;
	type = "Default";
	return ;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << "Copy AAnimal's constructor called" << std::endl;
	type = src.type;
	return ;
}

AAnimal&	AAnimal::operator=(const AAnimal& src)
{
	std::cout << "Assignement AAnimal's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Default AAnimal's destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Default AAnimal's sound" << std::endl;
}
