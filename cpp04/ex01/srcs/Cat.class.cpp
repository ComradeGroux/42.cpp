/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:20 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/11 17:42:33 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Default Cat's constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
	return ;
}

Cat::Cat(const Cat& src): Animal()
{
	std::cout << "Copy Cat's constructor called" << std::endl;
	type = src.type;
	return ;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Assignement Cat's constructor called" << std::endl;
	if (this != &src)
	{
		type = src.type;
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
