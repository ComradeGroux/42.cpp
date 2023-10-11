/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:20 by vgroux            #+#    #+#             */
/*   Updated: 2023/10/11 16:58:28 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void): AAnimal()
{
	std::cout << "Default Cat's constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
	return ;
}

Cat::Cat(const Cat& src): AAnimal()
{
	std::cout << "Copy Cat's constructor called" << std::endl;
	type = src.type;
	delete brain;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->ideas[i] = src.brain->ideas[i];
	return ;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Assignement Cat's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
		delete brain;
		brain = new Brain();
		for (int i = 0; i < 100; i++)
			brain->ideas[i] = src.brain->ideas[i];
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Default Cat's destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowwww" << std::endl;
}
