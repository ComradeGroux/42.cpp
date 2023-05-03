/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:26:47 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/03 16:02:16 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

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
	std::cout << "ScavTrap " << _name << " attacked " << target << ", but miss the enemy !" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " entered Gate keeper mode" << std::endl;
}
