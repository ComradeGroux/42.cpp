/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:08:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/03 15:54:18 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main(void)
{
	ClapTrap	a("Qqn");
	ClapTrap	b(a);
	ClapTrap	c = a;

	a.attack("b");
	b.takeDamage(10);
	c.beRepaired(3);
	return 0;
}
