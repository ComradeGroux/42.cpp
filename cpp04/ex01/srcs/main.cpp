/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:23:41 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:38:37 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include "WrongDog.class.hpp"

int	main(void)
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const Animal* meta = new Animal();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	
	std::cout << std::endl << "Wrong classes" << std::endl;
	const WrongAnimal* x = new WrongCat();
	const WrongAnimal* y = new WrongDog();
	const WrongAnimal* wrongmeta = new WrongAnimal();
	std::cout << x->getType() << " " << std::endl;
	std::cout << y->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	x->makeSound();
	y->makeSound();
	wrongmeta->makeSound();

	return 0;
}
