/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/12 17:18:57 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.template.tpp"
#include <cstdlib>

int	main(void)
{
	Array<int>	int_arr((unsigned int)42);
	srand(time(0));
	for (int i = 0; i < 42; i++)
	{
		int_arr[i] = rand();
	}

	try
	{
		std::cout << "Value at [3]: " << int_arr[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}
