/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:11:43 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/07 18:11:54 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	to_upper(char& c)
{
	c = std::toupper(c);
}

void	incr(int& i)
{
	i += 10;
}

void	str_to_upper(std::string& s)
{
	int i = 0;

	while (s[i])
	{
		s[i] = std::toupper(s[i]);
		i++;
	}
}

int	main(void)
{
	char char_array[] = {'a', 'b', 'c', 'd'};
	test("Char", char_array, sizeof(char_array)/sizeof(char_array[0]), to_upper);

	std::cout << std::endl;
	int int_array[] = {1, 2, 3, 4, 5};
	test("Int", int_array, sizeof(int_array)/sizeof(int_array[0]), incr);

	std::cout << std::endl;
	std::string strings_array[] = {"Bon", "Jour", "comment", "Va", "?"};
	test("Strings", strings_array, sizeof(strings_array)/sizeof(strings_array[0]), str_to_upper);
	return (0);
}