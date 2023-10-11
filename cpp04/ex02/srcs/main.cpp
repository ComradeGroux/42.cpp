/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:23:41 by vgroux            #+#    #+#             */
/*   Updated: 2023/10/11 17:08:40 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"
#include "Dog.class.hpp"

int	main(void)
{
	// AAnimal test;
	// (void)test;

	Cat	oups;
	oups.makeSound();
	Dog	woa;
	woa.makeSound();

	// Animal*	tab_ani[100];
	// for (int i = 0; i < 50; i++)
	// 	tab_ani[i] = new Dog();
	// for (int i = 50; i < 100; i++)
	// 	tab_ani[i] = new Cat();
	// for (int i = 0; i < 100; i++)
	// 	delete tab_ani[i];
	
	return 0;
}
