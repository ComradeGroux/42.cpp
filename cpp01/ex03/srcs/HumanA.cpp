/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:40:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/10 17:23:31 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _wp(weapon)
{
	return ;
}

HumanA::HumanA(const HumanA& src): _name(src.getName()), _wp(src._wp)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

HumanA& HumanA::operator=(const HumanA& rhs)
{
	_name = rhs.getName();
	_wp = rhs.getWeapon();
	return *this;
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _wp.getType() << std::endl;
}

std::string HumanA::getName(void) const
{
	return _name;
}

void		HumanA::setName(std::string name)
{
	_name = name;
}

Weapon		HumanA::getWeapon(void) const
{
	return _wp;
}

void		HumanA::setWeapon(const Weapon& weapon)
{
	_wp = weapon;
}
