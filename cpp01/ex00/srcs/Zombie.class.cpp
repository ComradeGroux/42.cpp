/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:55:44 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/03 20:04:43 by vgroux           ###   ########.fr       */
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

Zombie::Zombie(const Zombie &)
{
	;
}