/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:20 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:35:13 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "Default WrongCat's constructor called" << std::endl;
	type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal()
{
	std::cout << "Copy WrongCat's constructor called" << std::endl;
	type = src.type;
	return ;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << "Assignement WrongCat's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Default WrongCat's destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meowwww" << std::endl;
}
