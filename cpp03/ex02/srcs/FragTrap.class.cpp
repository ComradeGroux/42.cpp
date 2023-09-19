/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:31:00 by vgroux            #+#    #+#             */
/*   Updated: 2023/09/19 14:53:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap primary constructor called" << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	return ;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap assignement constructor called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_hp = src._hp;
		_ep = src._ep;
		_ad = src._ad;
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (_ep < 1)
		std::cout << "FragTrap " << _name << " can't high five because he doesn't have enough energy" << std::endl;
	else if (_hp < 1)
		std::cout << "FragTrap " << _name << " can't high five because he is dead" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " want to make a High Five" << std::endl;
		_ep--;
	}
}
