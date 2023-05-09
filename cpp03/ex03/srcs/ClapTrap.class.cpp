/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:49:05 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:19:42 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_ad = src._ad;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap assignement constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_ad = src._ad;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_ep >= 1)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " died or was already dead" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " take " << amount << " damages" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep >= 1 && _hp <= 10 - (int)amount)
	{
		_hp += amount;
		std::cout << "ClapTrap " << _name << " self repaired " << amount << " hit points" << std::endl;
		_ep--;
	}
	else
		std::cout << "ClapTrap " << _name << " doesn't have enough energy or he has too many hit points" << std::endl;
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

std::string	ClapTrap::getName(void) const
{
	return _name;
}
