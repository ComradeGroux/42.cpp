/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:30:49 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/10 13:34:10 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	_type = "Basic attack";
	return ;
}

Weapon::Weapon(std::string str): _type(str)
{
	return ;
}

Weapon::Weapon(const Weapon& src)
{
	_type = src.getType();
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string	Weapon::getType(void) const
{
	return _type;
}

void	Weapon::setType(std::string str)
{
	_type = str;
}
