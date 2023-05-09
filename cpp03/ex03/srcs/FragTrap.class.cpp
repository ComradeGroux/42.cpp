/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:31:00 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 16:27:13 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_hp = src._hp;
	_ep = src._ep;
	_ad = src._ad;
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
	std::cout << "FragTrap " << _name << " want to make a High Five" << std::endl;
}
