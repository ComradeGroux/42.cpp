/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:23:41 by vgroux            #+#    #+#             */
/*   Updated: 2023/10/11 13:55:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"
#include "Dog.class.hpp"

int	main(void)
{
	Animal*	tab_ani[100];
	for (int i = 0; i < 50; i++)
		tab_ani[i] = new Dog();
	for (int i = 50; i < 100; i++)
		tab_ani[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete tab_ani[i];


	// Cat basic;
	// {
	// 	Cat tmp = basic;
	// 	std::cout << std::endl << "tmp idea: " << tmp.getIdea(1) << "\tbasic idea: " << basic.getIdea(1) << std::endl;
	// 	std::cout << "It should destroy tmp here" << std::endl;
	// }
	// std::cout << std::endl;
	// basic.makeSound();
	// std::cout << std::endl << "basic idea: " << basic.getIdea(1) << std::endl;
	// std::cout << "It should destroy 3 times here" << std::endl;

	return 0;
}
