/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/16 16:09:28 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.template.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	tmp;

	std::vector<int>	vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
	std::list<int>		list(arr, arr + sizeof(arr)/sizeof(arr[0]));

	try
	{
		std::cout << "Trying to find value \'" << 5 << "\' in vect" << std::endl;
		tmp = easyfind(vect, 5);
		std::cout << "Value \'" << tmp << "\' found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Trying to find value \'" << 42 << "\' in list" << std::endl;
		tmp = easyfind(list, 42);
		std::cout << "Value \'" << tmp << "\' found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
