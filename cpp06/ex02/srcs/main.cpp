/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:38:27 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/07 17:52:30 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Base*	p = generate();

	identify(p);
	identify(*p);
}

Base*	generate(void)
{
	std::srand(time(0));

	int	random = std::rand() % 3;
	switch (random)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		return new A;
		break;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& tmp = dynamic_cast<A&>(p);
		(void)tmp;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		B& tmp = dynamic_cast<B&>(p);
		(void)tmp;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C& tmp = dynamic_cast<C&>(p);
		(void)tmp;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
