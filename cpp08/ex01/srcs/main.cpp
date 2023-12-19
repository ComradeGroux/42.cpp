/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/17 21:37:29 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>

void	print(int n)
{
	std::cout << n << std::endl;
}

int	main(void)
{
	Span	s(100000);

	s.addNumber(50);
	s.addNumber(30);
	s.addNumber(29);
	s.addNumber(30000);
	s.addNumber(-30);
	s.addNumber(-29);
	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;
	std::vector<int>	cp = s.getContent();
	s.addNumber(cp.begin(), cp.end());

	std::cout << "------------" << std::endl;
	cp = s.getContent();
	std::for_each(cp.begin(), cp.end(), print);
	return 0;
}
