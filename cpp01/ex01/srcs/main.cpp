/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:15 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/10 13:04:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int	main(void)
{
	int		n = 5;
	Zombie* horde = NULL;

	std::cout << std::endl << "horde de " << n << " membres" << std::endl;
	horde = zombieHorde(n, "foo");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] (horde);

	n = -42;
	std::cout << std::endl << "horde de " << n << " membres" << std::endl;
	horde = zombieHorde(n, "foo");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] (horde);

	n = 2;
	std::cout << std::endl << "horde de " << n << " membres" << std::endl;
	horde = zombieHorde(n, "foo");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] (horde);
	return (0);
}
