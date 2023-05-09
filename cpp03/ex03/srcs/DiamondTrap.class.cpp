/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:24:10 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 16:36:31 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::setName(name + "_clap_name");
	_name = name;
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_ad = FragTrap::_ad;
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

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
