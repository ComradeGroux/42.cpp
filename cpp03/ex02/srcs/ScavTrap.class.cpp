/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:26:47 by vgroux            #+#    #+#             */
/*   Updated: 2023/09/19 14:49:13 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) 
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap assignement constructor called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_hp = src._hp;
		_ep = src._ep;
		_ad = src._ad;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_ep < 1)
		std::cout << "ScavTrap " << _name << " can't attack because he doesn't have enough energy" << std::endl;
	else if (_hp < 1)
		std::cout << "ScavTrap " << _name << " can't attack because he is dead" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacked " << target << ", but miss the enemy !" << std::endl;
		_ep--;
	}
}

void	ScavTrap::guardGate(void)
{
	if (_ep < 1)
		std::cout << "ScavTrap " << _name << " can't enter in Gate keeper mode he doesn't have enough energy" << std::endl;
	else if (_hp < 1)
		std::cout << "ScavTrap " << _name << " can't enter in Gate keeper mode because he is dead" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " entered Gate keeper mode" << std::endl;
		_ep--;
	}
}
