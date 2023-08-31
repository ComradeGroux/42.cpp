/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:08:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/31 18:56:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"
#include "DiamondTrap.class.hpp"

int main(void)
{
	std::cout << "---------------\tCreation ClapTrap" << std::endl;
	ClapTrap	a("CLAP_qqn");
	ClapTrap	b(a);
	ClapTrap	c = a;
	
	std::cout << std::endl << "---------------\tCreation ScavTrap" << std::endl;
	ScavTrap	x("SCAV_qqch");
	ScavTrap	y(x);
	ScavTrap	z = x;
	
	std::cout << std::endl << "---------------\tCreation FragTrap" << std::endl;
	FragTrap	m("FRAG_ola");
	FragTrap	n(m);
	FragTrap	o = m;

	std::cout << std::endl << "---------------\tCreation DiamondTrap" << std::endl;
	DiamondTrap	q("DIAM_pepito");
	DiamondTrap	w(q);
	DiamondTrap	e = w;

	std::cout << std::endl << std::endl << "---------------\tOperation ClapTrap" << std::endl;
	a.attack("SOMEONE");
	b.takeDamage(10);
	c.beRepaired(3);
	std::cout << std::endl << "---------------\tOperation ScavTrap" << std::endl;;
	x.attack("SOMEONE");
	y.takeDamage(10);
	y.guardGate();
	z.beRepaired(3);
	// z.highFivesGuys();
	std::cout << std::endl << "---------------\tOperation FragTrap" << std::endl;;
	m.attack("SOMEONE");
	n.takeDamage(4);
	o.highFivesGuys();
	// o.guardGate();
	std::cout << std::endl << "---------------\tOperation DiamondTrap" << std::endl;;
	q.getData();
	q.attack("SOMEONE");
	q.whoAmI();
	q.highFivesGuys();
	q.beRepaired(2);
	std::cout << std::endl << "---------------\tDestruction" << std::endl;
	return 0;
}
