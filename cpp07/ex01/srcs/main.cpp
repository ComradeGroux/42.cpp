/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:11:43 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/07 18:22:08 by vgroux           ###   ########.fr       */
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
	i += 100;
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
	std::cout << "char array before ::iter" << std::endl;
	for (unsigned long i = 0; i < (sizeof(char_array)/sizeof(char_array[0])); i++)
		std::cout << char_array[i] << " ";
	std::cout << std::endl;
	::iter(char_array, sizeof(char_array)/sizeof(char_array[0]), to_upper);
	std::cout << "char array after ::iter" << std::endl;
	for (unsigned long i = 0; i < sizeof(char_array)/sizeof(char_array[0]); i++)
		std::cout << char_array[i] << " ";
	std::cout << std::endl;


	std::cout << std::endl;
	int int_array[] = {1, 2, 3, 4, 5};
	std::cout << "int array before ::iter" << std::endl;
	for (unsigned long i = 0; i < (sizeof(int_array)/sizeof(int_array[0])); i++)
		std::cout << int_array[i] << " ";
	std::cout << std::endl;
	::iter(int_array, sizeof(int_array)/sizeof(int_array[0]), incr);
	std::cout << "int array after ::iter" << std::endl;
	for (unsigned long i = 0; i < (sizeof(int_array)/sizeof(int_array[0])); i++)
		std::cout << int_array[i] << " ";
	std::cout << std::endl;


	std::cout << std::endl;
	std::string strings_array[] = {"Bon", "Jour", "comment", "Va", "?"};
	std::cout << "string array before ::iter" << std::endl;
	for (unsigned long i = 0; i < (sizeof(strings_array)/sizeof(strings_array[0])); i++)
		std::cout << strings_array[i] << " ";
	std::cout << std::endl;
	::iter(strings_array, sizeof(strings_array)/sizeof(strings_array[0]), str_to_upper);
	std::cout << "string array after ::iter" << std::endl;
	for (unsigned long i = 0; i < (sizeof(strings_array)/sizeof(strings_array[0])); i++)
		std::cout << strings_array[i] << " ";
	std::cout << std::endl;
	return (0);
}