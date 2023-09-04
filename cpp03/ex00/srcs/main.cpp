/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:08:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/09/04 12:25:22 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main(void)
{
	ClapTrap	a("A");
	ClapTrap	b(a);
	ClapTrap	c("C");
	c = a;
	
	std::cout << "1: "; a.attack("b");
	std::cout << "2: "; a.beRepaired(1); //si on peut pas etre reparer
	std::cout << "3: "; a.takeDamage(6); // si on peut prendre des degats
	std::cout << "4: "; a.beRepaired(100); // si on peut etre reparer
	std::cout << "4: "; a.takeDamage(20); // si on meurt
	std::cout << "5: "; a.takeDamage(100); // si on ne peut pas prendre de degat (deja mort)
	std::cout << "6: "; a.beRepaired(3); // si on ne peut plus etre repare (deja mort)
	std::cout << "7: "; a.attack("truc"); // si on ne peut plus attacker (deja mort)
	std::cout << std::endl << "---- Energy check ----" << std::endl;

	for (int i = 0; i < 11; i++)
	{
		std::cout << i + 1 << ": "; b.attack("someone");
	}
	b.beRepaired(42);
	return 0;
}
