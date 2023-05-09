/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:20 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:25:58 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.class.hpp"

WrongDog::WrongDog(void): WrongAnimal()
{
	std::cout << "Default WrongDog's constructor called" << std::endl;
	type = "WrongDog";
	return ;
}

WrongDog::WrongDog(const WrongDog& src): WrongAnimal()
{
	std::cout << "Copy WrongDog's constructor called" << std::endl;
	type = src.type;
	return ;
}

WrongDog& WrongDog::operator=(const WrongDog& src)
{
	std::cout << "Assignement WrongDog's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

WrongDog::~WrongDog(void)
{
	std::cout << "Default WrongDog's destructor called" << std::endl;
}

void	WrongDog::makeSound(void) const
{
	std::cout << "Bark bark bark" << std::endl;
}
