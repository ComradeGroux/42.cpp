/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/15 19:21:59 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.template.tpp"
#include <cstdlib>

#define NB_ELEM 5

int	main(void)
{
	srand(time(0));

	Array<int>	int_arr(NB_ELEM);
	for (int i = 0; i < NB_ELEM; i++)
		int_arr[i] = rand();
	try
	{
		std::cout << "Value at int_arr[0] : " << int_arr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Array<std::string>	void_arr;
	try
	{
		std::cout << "Value at void_arr[0]: " << void_arr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Array<char>	char_arr(NB_ELEM);
	for (int i = 0; i < NB_ELEM; i++)
		char_arr[i] = rand() % 128; // random char (0 / 127)
	try
	{
		std::cout << "Value at char_arr[0]: " << char_arr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Array<std::string>	str_arr(NB_ELEM);
	for (int i = 0; i < NB_ELEM; i++)
		str_arr[i] = "woaw c'est une string";
	try
	{
		std::cout << "Value at str_arr[0] : \"" << str_arr[0] << "\"\tLength of str_arr[0]: " << str_arr[0].length() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
