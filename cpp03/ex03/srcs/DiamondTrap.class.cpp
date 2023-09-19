/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:24:10 by vgroux            #+#    #+#             */
/*   Updated: 2023/09/19 14:57:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = name;
	_hp = FragTrap::_defaultHP;
	_ep = ScavTrap::_defaultEP;
	_ad = FragTrap::_defaultAD;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src._name + "_clap_name"), ScavTrap(src._name), FragTrap(src._name)
{
	std::cout << "DiamonTrap copy constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_ad = src._ad;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap assignement constructor called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_hp = src._hp;
		_ep = src._ep;
		_ad = src._ad;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap's name is " << _name << " when ClapTrap's name was " << ClapTrap::_name << std::endl;
}

// void	DiamondTrap::attack(const std::string& target)
// {
// 	ScavTrap::attack(target);
// }
