/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:40:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/10 17:29:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _wp(NULL)
{
	return ;
}

HumanB::HumanB(const HumanB& src)
{
	_name = src.getName();
	*_wp = src.getWeapon();
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

HumanB& HumanB::operator=(const HumanB& rhs)
{
	_name = rhs.getName();
	*_wp = rhs.getWeapon();
	return *this;
}

void	HumanB::attack(void) const
{
	std::cout << _name << " attacks with ";
	if (_wp != NULL)
		std::cout << "their " << _wp->getType();
	else
		std::cout << "his bare hands";
	std::cout << std::endl;
}

std::string HumanB::getName(void) const
{
	return _name;
}

void		HumanB::setName(std::string name)
{
	_name = name;
}

Weapon		HumanB::getWeapon(void) const
{
	return *_wp;
}

void		HumanB::setWeapon(const Weapon& weapon)
{
	*_wp = weapon;
}
