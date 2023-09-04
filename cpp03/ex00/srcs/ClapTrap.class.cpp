/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:49:05 by vgroux            #+#    #+#             */
/*   Updated: 2023/09/04 12:33:43 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap(void): _name("Default"), _hp(_defaultHP), _ep(10), _ad(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Primary constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_ad = src._ad;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Assignement constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_ad = src._ad;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_ep < 1)
		std::cout << "ClapTrap " << _name << " can't attack because he doesn't have enough energy" << std::endl;
	else if (_hp < 1)
		std::cout << "ClapTrap " << _name << " can't attack because he is dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage !" << std::endl;
		_ep--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp < 1)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	else
	{
		_hp -= amount;
		if (_hp < 1)
			std::cout << "ClapTrap " << _name << " die" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " take " << amount << " damages" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep < 1)
		std::cout << "ClapTrap " << _name << " can't be repaired because he doesn't have enough energy" << std::endl;
	else if (_hp < 1)
		std::cout << "ClapTrap " << _name << " can't be repaired because he is already dead" << std::endl;
	else if (_hp < _defaultHP)
	{
		int	maxToHeal = _defaultHP - _hp;
		_ep--;
		_hp += amount;
		if (_hp > _defaultHP)
		{
			_hp = _defaultHP;
			std::cout << "ClapTrap " << _name << " self repaired " << maxToHeal << " hit points (now full life)" << std::endl;
		}
		else
			std::cout << "ClapTrap " << _name << " self repaired " << amount << " hit points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't be repaired because he is full life" << std::endl;
}
