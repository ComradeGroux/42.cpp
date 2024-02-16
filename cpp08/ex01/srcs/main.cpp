/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/16 17:15:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>
#include <cstdlib>

#define NB_ELEM 10

void	print(int n)
{
	std::cout << n << std::endl;
}

int	main(void)
{
	Span	s(NB_ELEM);

	for (size_t i = 0; i < NB_ELEM / 2; i++)
		s.addNumber(rand());
	std::cout << "Max size is " << s.getSize() << " when effective size is " << s.getContent().size()<< std::endl;
	std::vector<int>	cp = s.getContent();
	try
	{
		std::cout << "Must be ok...\t";
		s.addNumber(cp.begin(), cp.end());
		std::cout << "Was OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << std::endl << e.what() << '\n';
	}

	std::cout << "Shortest is " << s.shortestSpan() << " when longest is " << s.longestSpan() << std::endl;

	std::cout << "----\tTotal values store in Span" << std::endl;
	cp = s.getContent();
	std::for_each(cp.begin(), cp.end(), print);
	std::cout << "----\tEnd values store in Spain" << std::endl;
	try
	{
		std::cout << "Must throw an exception here (because SPAN is already at max size)" << std::endl;
		s.addNumber(42);
		std::cout << "Didn't throw an exception ?!?" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Shortest is " << s.shortestSpan() << " when longest is " << s.longestSpan() << std::endl;
	return 0;
}
