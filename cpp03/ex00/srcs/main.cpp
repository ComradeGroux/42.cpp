/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:08:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/31 18:26:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main(void)
{
	ClapTrap	a("Qqn");
	ClapTrap	b(a);
	ClapTrap	c = a;

	a.attack("b");
	b.takeDamage(6);
	b.takeDamage(20);
	c.beRepaired(3);
	return 0;
}
