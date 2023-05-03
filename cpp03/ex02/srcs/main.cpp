/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:08:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/03 15:52:59 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"

int main(void)
{
	std::cout << "---------------\tCreation ClapTrap" << std::endl;

	ClapTrap	a("Qqn");
	ClapTrap	b(a);
	ClapTrap	c = a;
	
	std::cout << "---------------\tCreation ScavTrap" << std::endl;

	ScavTrap	x("oka");
	ScavTrap	y(x);
	ScavTrap	z = x;
	
	std::cout << "---------------\tOperation" << std::endl;
	a.attack("b");
	b.takeDamage(10);
	c.beRepaired(3);
	std::cout << std::endl;
	x.attack("y");
	y.takeDamage(10);
	y.guardGate();
	z.beRepaired(3);
	std::cout << "---------------\tDestruction" << std::endl;
	return 0;
}
