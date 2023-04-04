/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:55:44 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/04 11:26:15 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie(void)
{
	std::cout << "Default constructor was called" << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << name << " constructor was called" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << getName() << " was destructed" << std::endl;
	return ;
}

Zombie::Zombie(const Zombie& src)
{
	std::cout << "Copy constructor was called" << std::endl;
	*this = src;
	return ;
}

Zombie&	Zombie::operator=(const Zombie& rhs)
{
	_name = rhs._name;
	return *this;
}

std::string	Zombie::getName(void) const
{
	return _name;
}

void	Zombie::setName(std::string newName)
{
	this->_name = newName;
}

void	Zombie::announce(void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}