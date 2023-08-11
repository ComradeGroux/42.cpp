/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:20 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/11 17:43:21 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Default Dog's constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
	return ;
}

Dog::Dog(const Dog& src): Animal()
{
	std::cout << "Copy Dog's constructor called" << std::endl;
	type = src.type;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return ;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Assignement Dog's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Default Dog's destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark bark bark" << std::endl;
}
