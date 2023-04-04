/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:15 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/04 14:09:00 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int	main(void)
{
	Zombie	z1 = Zombie("Foo");
	Zombie	z2 = Zombie(z1);

	randomChump("Random name");
	z2.announce();
	Zombie* z3 = newZombie("newOne");
	z3->announce();
	delete(z3);
	return (0);
}
